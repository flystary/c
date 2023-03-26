#include<stdio.h>

// 错误处理
//  errno 设置为 0，这是一种良好的编程习惯。0 值表示程序中没有错误。
// errno、perror() 和 strerror()
/*
perror() 和 strerror() 函数来显示与 errno 相关的文本消息。
perror()    显示您传给它的字符串，后跟一个冒号、一个空格和当前 errno 值的文本表示形式。
strerror() 返回一个指针，指针指向当前 errno 值的文本表示形式。
*/

#include<errno.h>
#include<string.h>

extern int errno;

int file()
{
    FILE * pf;
    int errnum;
    pf = fopen("unexist.txt", "rb");

    if (pf == NULL) {
        errnum = errno;
        fprintf(stderr, "错误号： %d\n", errno);

        perror("通过perror 输出错误");
        fprintf(stderr, "打开文件错误： %s\n", strerror(errnum));
    } else {
       fclose(pf);
    }

    return 0;
}

// 被零除的错误
#include<stdlib.h>

void zero() {
    int dividend = 20;
    int divisor  = 0;
    int quotient;

    if (divisor == 0) {
        fprintf(stderr, "除数为0 ...\n");
        exit(-1);
    }
    quotient = dividend / divisor ;
    fprintf(stderr, "quotient 变量的值为 : %d\n", quotient );

    exit(0);
}


// 程序退出状态

int status()
{
    int dividend = 20;
    int divisor = 5;
    int quotient;

    if( divisor == 0){
        fprintf(stderr, "除数为 0 退出运行...\n");
        exit(EXIT_FAILURE);
    }
    quotient = dividend / divisor;
    fprintf(stderr, "quotient 变量的值为: %d\n", quotient );

    exit(EXIT_SUCCESS);

}
int main()
{
    file();
    printf("--------------------------\n");
    // zero();
    // printf("--------------------------\n");
    status();

    return 0;
}