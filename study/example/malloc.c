#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define N 16

void my_malloc1(char *str)
{
    str = malloc(sizeof(char)*N);
}

void my_malloc2(char **str)
{
    *str = malloc(sizeof(char)*N);
}

void *my_malloc3()
{
    char *str = malloc(sizeof(char)*N);
}

// 1.是通过传指针的地址给函数当参数；
// 2.是在通过函数返回值内返回一个申请好的内存。
int main(void)
{
    char *p1;
    char *p2;
    char *p3;

    my_malloc1(p1);
    printf("%d\n", sizeof(p1));
    my_malloc1(&p2);  
    printf("%d\n", sizeof(p2));
    p3 =  my_malloc3();  
    printf("%d\n", sizeof(p3));
    
    free(p1);
    p1 = NULL;
    
    // free(&p2);
    // p2 = NULL;
    free(p3);
    p3 = NULL;

    return 0;
}

