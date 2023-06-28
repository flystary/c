#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <errno.h>


int uart_open(const char *uart_path);
int uart_config(int fd);
int uart_write(int fd, char *vptr, size_t lenth);
int uart_read(int fd, char *bufptr, int BUFF_SIZE);//串口读取数据
int uart_close(int fd);

int uart_open(const char *uart_path){
    assert(uart_path);    //检测串口路径是否存在
    // 为了简单,非阻塞的形式打开串口,通过sleep 50ms来控制,比较傻
    int fd = open(uart_path, O_RDWR|O_NOCTTY|O_NDELAY);
    if(fd < -1) {
        perror("uart open failed!");
        return -1;
    }
    return fd;
}

uart_close(int fd){
    assert(fd);//assert先检查文件描述符是否存在
    close(fd);
    return 0;
}

int uart_config(int fd){
    struct termios uart;
    if(tcgetattr(fd, &uart) != 0) {
        perror("tcgetattr failed!");
        return -1;
    }

    cfsetispeed(&uart,B115200);//设置输入波特率115200
    cfsetospeed(&uart,B115200);//设置输出波特率115200

    //8N1
    uart.c_cflag &= ~CSIZE;
    uart.c_cflag |= CS8;     //设置数据位为8
    uart.c_cflag &= ~PARENB; //不校验
    uart.c_cflag &= ~CSTOPB; //1个停止位

    //uart.c_cflag |= CRTSCTS;                       //进行硬件流控制
    //uart.c_cflag &= ~(IXON | IXOFF | IXANY);       //关闭软件流控制
    uart.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG );//原始输入模式
    uart.c_cc[VTIME] = 0;   //设置等待时间为0
    uart.c_cc[VMIN] = 1;    //设置最小接受字符为1
    tcflush(fd,TCIFLUSH);   //清空输入缓冲区
    //激活配置
    if(tcsetattr(fd, TCSANOW, &uart) <0 ) {
        perror("tcgetattr failed!");
        return -1;
    }
    return 0;
}

int uart_write(int fd, char *vptr , size_t lenth){
    int bytes_write;
    while ( bytes_write = write(fd, vptr, lenth)) {
        // write失败
        if(bytes_write == -1 )
            return -1;
        // 所有数据都write成功
        else if(bytes_write == lenth)
            return 0;
        // 只write了部分数据，剩下的继续write
        else if(bytes_write > 0) {
            vptr += bytes_write;
            lenth -= bytes_write;
        }
    }

    return -1;
}

int uart_read(int fd, char* bufptr, int BUFF_SIZE){
    char buffer[BUFF_SIZE];
    // tmp指针指向buffer的空闲空间
    char* tmp=buffer;
    int bytes_read;
    while ((bytes_read = read(fd, tmp, buffer + sizeof(buffer) - tmp - 1)) > 0) {
        //printf("read bytes_read:%d %d\n",bytes_read, tmp-buffer);
        tmp += bytes_read;
    }
    *tmp = '\0';

    int i,j=0;
    tmp=buffer;
    // 多行合并成一行
    // 有些串口会把输入回显出来，合并成一行，然后进行字符串比较
    for(i=0; i<BUFF_SIZE-1;i++){
        //printf("%d %d\n",i,*(tmp+i));
        if(*(tmp+i) == '\0') break;
        if(*(tmp+i) == '\n' || *(tmp+i) == '\r'){
            j++;
            continue;
        }
        *(bufptr+i-j) = *(tmp+i);
        //printf("%d\n",*(tmp+i));
    }
    bufptr[BUFF_SIZE-1] = '\0';
    return 0;
}

#define BUFF_SIZE 255
char esim[BUFF_SIZE] = "unknown";
static int MAX=20;



int main(int argc, char const *const *argv) {
    const char *uart_path;
    if (argc == 2){
        uart_path = argv[1];
    } else {
        uart_path = "/dev/ttyUSB2";
    }

    char result[BUFF_SIZE];

    int modem = uart_open(uart_path);
    if (modem < 0) {
        return -1;
    }

    if (uart_config(modem) < 0) {
        uart_close(modem);
        return -2;
    }

    // 先把之前的信息读取出来
    // uart_read(modem, result, BUFF_SIZE);
    // 发送AT命令
    uart_write(modem, "AT\r", 4);
    usleep(50000);
    uart_read(modem, result, BUFF_SIZE);
    // printf("result: %s\n",result);
    // 有些串口会把输入回显出来
    if(strncmp(result,"OK",2) != 0 && strncmp(result,"ATOK",4) != 0 ){
        // 执行at命令，输出99，退出

        uart_close(modem);
        return 0;
    }


    uart_write(modem, "AT+CGSN\r", 9);
    usleep(50000);
    uart_read(modem, result, BUFF_SIZE);

    int len;
    if(strlen(result) > 15) {
        if (strlen(result) <= 17) {
            len = strlen(result)-2;
            memcpy(esim, result, len);
            esim[len] = '\0';
        } else {
            len = strlen(result)-9;
            memcpy(esim, result+7, len);
            esim[len] = '\0';
        }
    }

    uart_close(modem);
    printf("%s\n", esim);
    return 0;
}
