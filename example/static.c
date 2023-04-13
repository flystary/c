#include <stdio.h>

static int y = 0;

void foo()
{
    static int x = 0;
    x++;
    y = y + 2;
    printf("%d\n", x);
}

int xx()
{
    printf("y : %d\n", y);
    foo();
    printf("y : %d\n", y);
    foo();
    printf("y : %d\n", y);
    foo();
    printf("y : %d\n", y);
    return 0;
}

int yy()
{
    int i, num = 2;

    for (i = 0; i < 3; i++)
    {
        printf("num 变量为 %d \n", num);
        num++;
        {
            auto int num = 1;
            printf("内置模块 num 变量为 %d \n", num);
            num++;
        }
    }

    return 0;
}

int zz()
{
    int i, num = 2;

    for (i = 0; i < 3; i++)
    {
        printf("num 变量为 %d \n", num);
        num++;
        {
            static int num = 1;
            printf("内置模块 num 变量为 %d \n", num);
            num++;
        }
    }

    return 0;
}

int a, b, c;

void add()
{
    int a;
    a = 3;
    c = a + b;
}

int ss()
{
    a = b = 4;
    add();
    printf("c 的值为 %d\n", c);

    return 0;
}

int mm()
{
    register int i;
    int tmp = 0;
    for (i = 1; i <= 100; i++)
        tmp += i;

    printf("sum %d\n", tmp);

    return 0;
}
int main()
{
    xx();
    printf("---------------------------------\n");
    yy();
    printf("---------------------------------\n");
    zz();
    printf("---------------------------------\n");
    ss();
    printf("---------------------------------\n");
    mm();
    return 0;
}