//异步读实现(检查方式)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <aio.h>
#include <string.h>
#include <fcntl.h>
 
#define BUFF_SIZE 1024  //缓冲大小
 
int main(){
	//1. 准备缓冲区
	struct aiocb cb = {0};
 
	int fd = open("test.txt",O_RDONLY);
	if(-1 == fd) printf("文件打开失败:%m\n"),exit(-1);
	printf("文件打开成功!\n");
	//2. 异步读取文件数据
	cb.aio_buf = malloc(BUFF_SIZE + 1); //开辟内存空间
	memset(cb.aio_buf,0,BUFF_SIZE + 1); //清空内存
	cb.aio_fildes = fd;					//文件描述符
	cb.aio_nbytes = BUFF_SIZE;			//读取数据大小
	cb.aio_offset = 0;					//文件偏移量
 
	int r = aio_read(&cb);
	if(-1 == r) printf("异步读取失败:%m\n"),close(fd),exit(-2);
	printf("异步读取成功!\n");
 
	//3. 检查是否读取数据完毕
	int n = 0;
	while(aio_error(&cb)) n++;
 
	//4. 得到数据
	r = aio_return(&cb);
	if(r > 0){
		printf("拿到了数据:n:%d,r:%d bytes,data: %s\n",
			n,r,cb.aio_buf);
	}
 
	//5. 释放内存 关闭文件
	free(cb.aio_buf);
	close(fd);
 
	return 0;
}
