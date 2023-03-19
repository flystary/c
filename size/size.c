#include<stdio.h>
#include<limits.h>
#include <float.h>


int _hello1()
{
    char *a;

    a = "hello";
    printf("%s\n", a);
    // a = "liql";
    // printf("%s\n", a);
    printf("in size: %lu \n", sizeof(int));
    printf("in size: %lu \n", sizeof(*a));

    return 0;
}



int main()
{
    printf("float max size : %lu \n", sizeof(float));
    printf("float MIN size : %E\n", FLT_MIN);
    printf("float MAX size : %E\n", FLT_MIN);
    printf(" %d\n", FLT_DIG);

    _hello2();

    if (sum() == 0) {
        printf("sum");
    }

    return 0;
}


void _hello2()
{
    int i = 0;
    float f = 3.14;
    double d = i + f;

    double e = 3.141596535;
    int g = (int)d;

    printf("%d\n", d);
    printf("%d\n", g);
    printf("%s\n", "hello");

    return;
}


int  sum()
{
    float f, x = 3.6, y = 5.2;
    int i = 4, a, b;
    a = x + y;
    b = (int)(x + y);
    f = 10 / i;
    printf("a=%d, b=%d, f=%f, x=%f\n", a, b, f, x);

    return 0;
}