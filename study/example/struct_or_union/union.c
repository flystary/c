#include <stdio.h>

union C
{
    int   i;
    char  c;
};


int main()
{
    union C c;
    c.i = 1;

    printf("c.c == %d\n", c.c);
    printf("c.i == %d\n", c.i);

    return 0;
}
