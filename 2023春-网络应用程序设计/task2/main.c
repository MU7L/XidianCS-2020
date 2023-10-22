#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <string.h>

#define SHARED_MEMORY_SIZE 65536 // 64kb
#define DELAY 5000

void P(int semid)
{
    struct sembuf buf = {0, -1, 0};
    semop(semid, &buf, 1);
}

void V(int semid)
{
    struct sembuf buf = {0, 1, 0};
    semop(semid, &buf, 1);
}

int get_sem_id()
{
    key_t keyid = ftok("testforsem", 102);
    if (keyid < 0)
    {
        perror(" get key failed");
        return -1;
    }
    int semid = semget(keyid, 1, IPC_CREAT | 0660);
    if (semid < 0)
    {
        perror("get semphore failed");
        return -1;
    }
    return semid;
}

int main()
{
    pid_t pid1, pid2;
    int pipefd1[2], pipefd2[2];
    int shmid;
    char *shared_memory;

    // 创建管道1
    if (pipe(pipefd1) == -1)
    {
        perror("pipe1");
        return 1;
    }

    // 创建管道2
    if (pipe(pipefd2) == -1)
    {
        perror("pipe2");
        return 1;
    }

    // 创建共享内存
    shmid = shmget(IPC_PRIVATE, SHARED_MEMORY_SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("shmget");
        return 1;
    }

    // 连接共享内存
    shared_memory = (char *)shmat(shmid, NULL, 0);
    if (shared_memory == (char *)-1)
    {
        perror("shmat");
        return 1;
    }

    // 创建子进程1
    pid1 = fork();

    if (pid1 < 0)
    {
        perror("fork1");
        return 1;
    }
    else if (pid1 == 0)
    {
        printf("Child 1 run\n");
        // 子进程1 从1读 向2写

        // 关闭管道1的写端
        close(pipefd1[1]);

        // 关闭管道2的读端
        close(pipefd2[0]);

        // 写入数据到管道2
        char message[] = "Hello from Child 1!";
        printf("Child 1 sent: %s\n", message);
        write(pipefd2[1], message, sizeof(message));

        // 从管道1读取数据
        char buffer[32];
        int nbytes = read(pipefd1[0], buffer, sizeof(buffer));
        if (nbytes == -1)
        {
            perror("read1");
            return 1;
        }

        // 在读取每个字节后延时0.5ms
        printf("Child 1 received: ");
        for (int i = 0; i < nbytes; i++)
        {
            usleep(DELAY);
            printf("%c", buffer[i]);
        }
        printf("\n");

        // 关闭管道2的写端
        close(pipefd2[1]);

        // 写入数据到共享内存
        printf("Child 1 wrote: %s\n", message);
        memcpy(shared_memory, message, sizeof(message));

        // 关闭共享内存
        shmdt(shared_memory);

        printf("Child 1 exit\n");
        exit(EXIT_SUCCESS);
    }

    // 创建子进程2
    pid2 = fork();

    if (pid2 < 0)
    {
        perror("fork2");
        return 1;
    }
    else if (pid2 == 0)
    {
        // 子进程2 从2读 向1写
        printf("Child 2 run\n");

        // 关闭管道1的读端
        close(pipefd1[0]);

        // 关闭管道2的写端
        close(pipefd2[1]);

        // 从管道2读取数据
        char buffer[32];
        int nbytes = read(pipefd2[0], buffer, sizeof(buffer));
        if (nbytes == -1)
        {
            perror("read2");
            return 1;
        }

        // 在读取每个字节后延时0.5ms
        printf("Child 2 received: ");
        for (int i = 0; i < nbytes; i++)
        {
            usleep(DELAY);
            printf("%c", buffer[i]);
        }
        printf("\n");

        // 写入数据到管道1
        char message[] = "Hello from Child 2!";
        printf("Child 2 sent: %s\n", message);
        write(pipefd1[1], message, sizeof(message));

        // 关闭管道1的写端
        close(pipefd1[1]);

        // 从共享内存读取数据
        memcpy(buffer, shared_memory, sizeof(buffer));

        // 在读取每个字节后延时0.5ms
        printf("Child 2 read: ");
        for (int i = 0; i < sizeof(buffer); i++)
        {
            usleep(DELAY);
            printf("%c", buffer[i]);
        }
        printf("\n");

        // 关闭共享内存
        shmdt(shared_memory);

        printf("Child 2 exit\n");
        exit(EXIT_SUCCESS);
    }

    // 父进程

    // 等待子进程结束
    wait(NULL);
    wait(NULL);

    // 关闭管道1
    close(pipefd1[0]);
    close(pipefd1[1]);

    // 关闭管道2
    close(pipefd2[0]);
    close(pipefd2[1]);

    // 删除共享内存
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
