#include <stdio.h>


int mem(void)
{
    struct A
    {
        char    a;
        int     b;
        char    c;
    } a = { 'a', 10, 'c'};

    printf("size of a = %d\n", sizeof(a));

    return 0;
}

int mem_1(void)
{
    struct A
    {
        int     b;
        char    a;
        char    c;
    } a = {10, 'a', 'c'};

    printf("size of a = %d\n", sizeof(a));

    return 0;

}

int mem_2(void)
{
    struct A
    {
        char    a;
        char    c;
        int     b;
    } a = {'a', 'c', 12};

    printf("size of a = %d\n", sizeof(a));

    return 0;
}


int main()
{

    mem();
    mem_1();
    mem_2();

    return 0;
}
