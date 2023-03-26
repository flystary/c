#include<stdio.h>

// 递归指的是在函数的定义中使用函数自身的方法。

/*
void recursion()
{
   statements;
   ... ... ...
   recursion(); // 函数调用自身
   ... ... ...
}

int main()
{
   recursion();
}
*/

//阶乘
double factorial(unsigned int i)
{
    if (i <= 1)
    {
        return 1;
    }

    return i * factorial(i - 1);
}

int test()
{
    int i = 15;
    printf("!%d is %f\n", i, factorial(i));

    return 0;
}


int fibonaci(int i)
{
    if (i == 0)
    {
        return 0;
    }
    if (i == 1)
    {
        return 1;
    }

    return fibonaci(i-1) + fibonaci(i-2);
}

int test1()
{
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d\t\n", fibonaci(i));
    }
    return 0;
}
int main()
{
    test();
    printf("--------------------------\n");

    test1();
    return 0;
}