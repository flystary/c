#include <stdio.h>
#include <stdlib.h>

int **get(int N, int M)
{
    int i, **array;

    array = malloc(N * sizeof(int *));
    for (i = 0; i < N; i++)
        array[i] = malloc(M * sizeof(int));

    return array;
}

void getNoReturn(int ***array, int N, int M)
{
    /* Check if allocation succeeded. (check for NULL pointer) */
    int i;
    *array = malloc(N * sizeof(int *));
    for (i = 0; i < N; i++)
        (*array)[i] = malloc(M * sizeof(int));
}

void fill(int **p, int N, int M)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        int z = 1;
        z = z + i;
        for (j = 0; j < M; j++)
        {
            p[i][j] = z;
            z++;
        }
    }
}

int print(int **p, int N, int M)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
            // printf("array[%d][%d] = %d", i, j, p[i][j]);
            printf("%d ", p[i][j]);
        printf("\n");
    }
}

int echo(int **p, int N)
{
    int i, j, sum1, sum2;
    printf("----------\n");
    for (i = 0; i < N; i++)
    {
        int b = p[i][i];
        printf("%d ", b);
        sum1 += b;
    }
    printf("左对角线之和为：%d\n", sum1);

    for (j = N; j > 0; j--)
    {
        int c = p[j - 1][N - j];
        printf("%d ", c);
        sum2 += c;
    }
    printf("右对角线之和为：%d\n", sum2);

    return 0;
}
void freeArray(int **p, int N)
{
    int i;
    for (i = 0; i < N; i++)
        free(p[i]);
    free(p);
}

int main(void)
{
    int **p;
    // getNoReturn(&p, 2, 5);
    p = get(6, 6);
    fill(p, 6, 6);
    print(p, 6, 6);
    echo(p, 6);
    freeArray(p, 6);
    return 0;
}