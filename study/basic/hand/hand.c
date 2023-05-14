#include<stdio.h>

void runoob()
{
    int var_runoob = 10;
    int  *p;
    p = &var_runoob;

    printf("var_runoob 变量的地址: %p\n", p);
}

// type *var_name;

// int    *ip;    /* 一个整型的指针 */
// double *dp;    /* 一个 double 型的指针 */
// float  *fp;    /* 一个浮点型的指针 */
// char   *ch;    /* 一个字符型的指针 */


void p()
{
    int var = 20;
    int *ip;
    ip = &var;
    printf("var 变量的地址: %p\n", &var);
    printf("ip 变量存储的地址： %p\n", ip);
    printf("*ip变量的值: %d\n", *ip);
}


void ptr()
{
    int *ptr = NULL;
    printf("ptr 的地址是 %p\n", ptr);

    if(ptr){
        printf("not is nil\n");
    }

    if(!ptr){
        printf("is nil\n");
    }

}


int main()
{
    runoob();
    printf("------------------------\n");
    p();
    printf("------------------------\n");
    ptr();
    return 0;
}
