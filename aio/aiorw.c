#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <aio.h>
#include <string.h>
#include <fcntl.h>

#define BUFF_SIZE 1024
#define AIO_LIST_NUM 2

int main()
{
    struct aiocb rcb = {0};
    struct aiocb wcb = {0}
    
    struct aiocb* aiocb_list[AIO_LIST_NUM] = {NULL};

    int rfd = open("test.txt", O_RDONLY);
    if(-1 == rfd) {
        printf("打开文件失败: %m\n");
        exit(-1);
    }
    printf("文件打开成功!\n");

    wcb.aio_buf = malloc(BUFF_SIZE + 1);
    memset(wcb.aio_buf, 0, BUFF_SIZE + 1);
    strcpy(wcb.aio_buf, "HELLO AIO\n");
    wcb.aio_fildes = wfd;
    wcb.aio_nbytes = strlen("HELLO AIO\n");
    wcb.aio_lio.opcode = LIO_WRITE;
    
    aiocb_list[1] = &wcb;
    
    int r = lio_listio(LIO_WAIT, aiocb_list, AIO_LIST_NUM, NULL);
    printf("lio_listio r: %d\n", r);

    r = aio_return(&rcb);
    if(r > 0){
        printf("拿到了数据:r:%d bytes,data: %s\n",
            r,rcb.aio_buf);
    }
 
    r = aio_return(&wcb);
    if(r > 0){
        printf("写入数据成功:r %d\n",r);
    }

    free(rcb.aio_buf);
    free(wcb.aio_buf);
    close(rfd);
    close(wfd);

    return 0;
}
