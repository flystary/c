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


int main()
{
    echo();

    return 0;
}