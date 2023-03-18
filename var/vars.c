// #include<stdio.h>

// int x;
// int y;
// int addtwonum()
// {
//     extern int x;
//     extern int y;
//     x = 1;
//     y = 2;
//     return x + y;
// }

// int main()
// {
//     int result;
//     result = addtwonum();
//     printf("result: %d\n", result);

//     return 0;
// }

#include<stdio.h>

int x = 3;
int y = 4;
int add_sum();

int main(void)
{
    int result;
    result = add_sum(x, y);
    printf("%d\n", result);
    return 0;
}
