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
int main()
{
    xx();
    printf("---------------------------------\n");
    yy();
    return 0;
}