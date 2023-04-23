#include <stdio.h>

int x()
{
    long sum = 4, s = 4;
    int j;
    for (j = 2; j <= 8; j++)
    {
        printf("%d位数为奇数的个数%ld\n", j - 1, s);
        if (j <= 2)
            s *= 8;
        else
            s *= 8;
        sum += s;
    }
    printf("%d位数为奇数的个数%ld\n", j - 1, s);
    printf("奇数的总个数为：%ld\n", sum);
    // system("pause");
    return 0;
}

#include <stdlib.h>
/*
int is_primer(unsigned int n);

int y()
{
    unsigned int n, i;
    do
    {
        printf("请输入一个偶数: \n");
        scanf("%d", &n);
    } while (n % 2 != 0);

    for (i = 1; i < n; i++)
        printf(is_primer(i) && is_primer(n - i));
    printf("偶数%d可以分解成%d和%d两个素数的和\n", n, i, n - i);

    return 0;
}

int is_primer(unsigned int n)
{
    int i;
    if (n < 4)
        return 1;
    else if (n % 2 == 0)
        return 0;
    else
        for (i = 3; i < sqrt(n) + 1; i++)
            if (n % i == 0)
                return 0;

    return 1;
}
*/
int z()
{
    int p, i;
    long int sum = 9;
    printf("请输入一个素数: \n");
    scanf("%d", &p);

    for (i = 1;; i++)
        if (sum % p == 0)
            break;
        else
            sum = sum * 10 + 9;

    printf("素数%d能整除%d个9组成的数%ld\n", p, i, sum);
    return 0;
}

int s()
{
    int n, i, j;
    for (i = 0; i < 7; i++)
    {
        scanf("%d", &n);
        if (n > 50)
        {
            printf("请重新输入:\n");
            i--;
        }
        else
        {
            for (j = 0; j < n; j++)
                printf("*");
        }
        printf("\n");
    }
    return 0;
}

#define M 5
int m()
{
    int a[M] = {1, 2, 3, 4, 5};
    int i, j, t;
    i = 0;
    j = M - 1;
    while (i < j)
    {
        t = *(a + i);
        // printf("%c\n", t);
        *(a + i) = *(a + j);
        *(a + j) = t;
        i++;
        j--;
    }

    for(i=0;i<M;i++)
    {
        printf("%d\n", *(a+i));
    }

    return 0;
}

int main()
{
    // x();
    // printf("\n");
    // y();
    // z();
    // printf("\n");
    // s();
    m();

    return 0;
}