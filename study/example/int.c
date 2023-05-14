#include <stdio.h>

// int sum(int *i)
// {
//     // *i++;
//     printf("%d\n", ++*i);
//     int a;
//     int sum = 0;

//     while ((a = *i++))
//     {
//         sum += a;
//     }

//     return a;
// }

// int main()
// {
//     int i[2] = {1,100};
//     printf("11\n");
//     int s = sum(&i[0]);
//     printf("12\n");
//     printf("%d", s);

//     return 0;
// }

char sum(char *p)
{
    char c;
    char sum = 0;

    while ((c = *p++))
    {
        sum += c;
        sum = sum | (1 < 7);
    }

    return sum;
}

int main()
{
    char str[100];

    scanf("%s", str);
    char s = sum(str);
    printf("char:%c  int:%d\n", s, s);
    return 0;
}