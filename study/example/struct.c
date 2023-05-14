#include <stdio.h>

struct student
{
    int x;
    char c;
} a;

int echo()
{
    a.x = 3;
    a.c = 'a';
    f(a);
    printf("%d, %c\n", a.x, a.c);

    return 0;
}

f(struct student b)
{
    b.x = 20;
    b.c = 'y';
}

struct programming
{
    float constant;
    char *pointer;
};

int z()
{
    struct programming variable;
    char string[] = "菜鸟教程：https://www.runoob.com";

    variable.constant = 1.23;
    variable.pointer = string;

    printf("%f\n", variable.constant);
    printf("%s\n", variable.pointer);

    return 0;
}

int main()
{
    echo();
    z();
    return 0;
}