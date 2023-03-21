#include<stdio.h>

// 函数指针
typedef int (*fun_ptr)(int, int); // 声明一个指向同样参数、返回值的函数指针类型

int max(int x, int y)
{
    return x > y ? x : y;
}

int getMax(void)
{
    int (* p)(int, int) = & max;
    int a, b, c, d;

    printf("请输入三个数字:");
    scanf("%d %d %d", & a, & b, & c);
    // d = max(max(a, b), c);
    d = p(p(a, b), c);

    printf("max is d: %d\n", d);
    return 0;
}

// 回调函数
#include<stdlib.h>
#include<stdio.h>

void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue();
}

int getNextRandomValue(void)
{
    return rand();
}

int main(void)
{
    int myarray[10];
    populate_array(myarray, 10, getNextRandomValue);
    for(int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}