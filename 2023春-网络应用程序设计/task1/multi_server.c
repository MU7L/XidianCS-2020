#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#define MAX_CONCURRENT_CLIENTS 10 // 最大并发客户端数
#define BUFFER_SIZE 1024          // 缓冲区大小

// TODO: 并行问题？
volatile int num_clients = 0; // 当前连接客户端数目

// 处理子进程退出 清除僵尸
void handle_sigchld(int sig)
{
    pid_t pid;
    int status;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        num_clients--;
        printf("当前进程数: %d\n", num_clients);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "命令: %s <IP address> <port>\n使用命令 ip addr 获得本机ip(172.28.235.7)\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 创建套接字
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // 绑定 IP 地址和端口号
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));
    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // 监听套接字
    if (listen(server_fd, MAX_CONCURRENT_CLIENTS) == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // 安装 SIGCHLD 信号处理器
    signal(SIGCHLD, handle_sigchld); // 回调

    // 进入主循环
    while (1)
    {
        printf("等待请求\n");
        // 接受客户端连接请求
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1)
        {
            if (errno != EINTR)
            {
                perror("accept");
            }
            continue;
        }

        // 创建子进程处理客户端请求
        pid_t pid = fork();
        num_clients++;
        if (pid == -1)
        {
            num_clients--;
            perror("fork");
            close(client_fd);
            continue;
        }

        else if (pid == 0)
        { // 子进程代码
            pid_t cpid = getpid();
            printf("[进程 %d] 建立连接\n", cpid);
            printf("当前进程数: %d\n", num_clients);

            // 读取客户端发送的服务请求时间
            char buffer[BUFFER_SIZE];
            memset(buffer, 0, sizeof(buffer));
            if (read(client_fd, buffer, sizeof(buffer)) == -1)
            {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // 延时服务请求时间
            int request_time = atoi(buffer);
            printf("[进程 %d] 请求时间: %d s\n", cpid, request_time);

            while(request_time) {
                sprintf(buffer, "[进程 %d] %d 秒后退出\n", cpid, request_time);
                if (write(client_fd, buffer, sizeof(buffer)) == -1)
                {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
                sleep(1);
                request_time--;
            }

            // 关闭客户端套接字并退出
            close(client_fd);
            printf("[进程 %d] 退出\n", cpid);
            exit(EXIT_SUCCESS);
        }

        else
        { // 父进程代码
            close(client_fd);
        }
    }

    return 0;
}
