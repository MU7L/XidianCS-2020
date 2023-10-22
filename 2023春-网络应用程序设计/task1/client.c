#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024 // 缓冲区大小

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "命令: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 创建套接字
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // 连接服务器
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));
    if (connect(client_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // 从终端读取服务请求时间
    char buffer[BUFFER_SIZE];
    printf("服务请求时间（秒）: ");
    fgets(buffer, sizeof(buffer), stdin);

    // 发送服务请求时间给服务器
    int request_time = atoi(buffer);
    if (send(client_fd, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // 等待服务完成并关闭套接字
    memset(buffer, 0, sizeof(buffer));
    while (request_time)
    {
        if (read(client_fd, buffer, sizeof(buffer)) == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("%s", buffer);
        request_time--;
    }

    close(client_fd);

    return 0;
}
