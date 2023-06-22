#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <aio.h>
#include <string.h>
#include <fcntl.h>

#define BUFF_SIZE 1024

int main()
{
    struct aiocb cb = {0};
    
    int fd = open("test.txt", O_RDONLY);
    if(-1 == fd) {
        printf("文件打开失败: %m\n");
        exit(-1);
    }
    printf("文件打开成功\n");

    cb.aio_buf = malloc(BUFF_SIZE + 1);
    memset(cb.aio_buf, 0, BUFF_SIZE + 1);
    cb.aio_fildes = fd;
    cb.aio_nbytes = BUFF_SIZE;
    cb.aio_offset = 0;

    int r = aio_read(&cb);
    if(-1 == r) {
        printf("异步读取失败: %m\d");
        close(fd);
        exit(-2);
    }
    printf("异步读取成功!\n");

    int n = 0;
    while(aio_error(&cb)) n++;

    r = aio_return(&cb);
    if (r > 0) {
        printf("拿到了数据:n:%d,r:%d bytes,data: %s\n",
            n,r,cb.aio_buf);
    }

    free(cb.aio_buf);
    close(fd);

    return 0;
}
