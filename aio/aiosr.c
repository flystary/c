#include <stdio.h>
#include <stdlib.h>
#include <unsitd.h>
#include <aio.h>
#include <string.h>
#include <fcntl.h>

#define BUFF_SIZE 1024
#define AIO_LIST_NUM 2

int main()
{
    struct aiocb cb = {0};

    struct aiocb* aiocb_list[AIO_LIST_NUM] = {0};
    
    int fd = open("test.txt", O_RDONLY);
    if(-1 == fd) {
        printf("文件打开失败: %m\n");
        exit(-1);
    }
    printf("文件打开成功\n");

    int r = aio_read(&cb);
    if(-1 == r) {
        printf("异步读取失败: %m\n");
        close(fd);
        exit(-2);
    }
    printf("异步读取成功!\n");

    aiocb_list[0] = &cb;
    printf("阻塞!\n");

    r = aio_suspend(aiocb_list, AIO_LIST_NUM, NULL);
    if(-1 == r) {
        printf("aio_suspend失败: %m\d");
        close(fd);
        exit(-3);
    }
    printf("aio_suspend成功!\n");
    printf("阻塞结束!\n");

    r = aio_return(&cb);
    if(r > 0) {
        printf("拿到了数据:r:%d bytes, data: %s\n",
        r, cb.aio_buf);
    }
    free(cb.aio_buf);
    close(fd);
    
    return 0;
}
