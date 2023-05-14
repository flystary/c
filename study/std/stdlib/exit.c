#include <stdio.h>
#include <stdlib.h>

int e_abort()
{
    FILE *fp;

    printf("准备打开 nofile.txt\n");
    fp = fopen("nofile.txt", "r");
    if (fp == NULL)
    {
        printf("准备终止程序\n");
        abort();
    }
    printf("准备关闭 nofile.txt\n");
    fclose(fp);

    return 0;
}

void func()
{
    printf("A\n");
}
int e_atexit()
{
    atexit(func);
    printf("启动主程序...\n");

    printf("退出主程序...\n");

    return (0);
}

int e_exit()
{
    printf("程序的开头....\n");

    printf("退出程序....\n");
    exit(0);

    printf("程序的结尾....\n");

    return (0);
}
int main()
{
    // e_abort();
    // e_atexit();
    e_exit();
    return 0;
}