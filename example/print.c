#include <stdio.h>
// #define N 3

int echo(int N)
{
    int i, j, a[N][N], sum1 = 0, sum2 = 0;
    printf("请输入矩阵(%d*%d): \n", N, N);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("----------\n");
    for (i = 0; i < N; i++)
    {
        int b = a[i][i];
        printf("%d ", b);
        sum1 += b;
    }
    printf("左对角线之和为：%d\n", sum1);

    /*
    printf("a[3][0] : %d\n", a[3][0]);
    printf("a[2][1] : %d\n", a[2][1]);
    printf("a[1][2] : %d\n", a[1][2]);
    printf("a[0][3] : %d\n", a[0][3]);
    */

    for (j = N; j > 0; j--)
    {
        int c = a[j-1][N-j];
        printf("%d ", c);
        sum2 += c;
    }
    printf("右对角线之和为：%d\n", sum2);

    return 0;
}

int main()
{
    echo(5);
    return 0;
}