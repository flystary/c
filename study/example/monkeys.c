#include <stdio.h>
#include <stdlib.h>

int mon()
{
    int x, i = 0, j = 1;
    while (i < 5)
    {
        x = 4 * j;
        for (i = 0; i < 5; i++)
        {
            if (x % 4 != 0)
            {
                break;
            }
            x = (x / 4) * 5 + 1;
        }
        j++;
    }
    printf("%d\n", x);

    return 0;
}
void output(long int b, long int i);
void output(long int b, long int i)
{
    printf("%ld = 800 * %ld + 9 * %ld\n", b, i, i);
}

int num()
{

    long int a, b, i;
    a = 809;
    for (i = 10; i < 100; i++)
    {
        b = i * a;
        if (b >= 1000 && b <= 10000 && 8 * i < 100 && 9 * i > 100)
        {
            output(b, i);
        }
    }
    return 0;
}

int main()
{
    mon();
    num();
    return 0;
}