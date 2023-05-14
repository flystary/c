#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main()
{
    char buf[1024];
    int sockfd;
    struct sockaddr_in saddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        perror("socket");
        return -1;
    }

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(8888);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = connect(sockfd, (struct sockaddr *)&saddr, sizeof(saddr));
    if (-1 == ret)
    {
        perror("connect");
        return -1;
    }

    while (1)
    {
        memset(buf, 0, sizeof(buf));
        scanf("%s", buf);
        ret = write(sockfd, buf, sizeof(buf));
        if (-1 == ret)
        {
            perror("write");
            return -1;
        }
        ret = read(sockfd, buf, sizeof(buf));
        if (-1 == ret)
        {
            perror("read");
            return -1;
        }
        printf("buf = %s\n", buf);
    }
}