#include <stdio.h>
#include <stdlib.h>

int x()
{
    int arr[20];
    int i, n, offset;
    printf("Total number?\n");

    scanf("%d", &n);
    printf("Input %d numbers. \n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Set your offset.\n");
    scanf("%d", &offset);
    printf("Offset is %d.\n", offset);
    // 打印滚动前数组
    print_arr(arr, n);
    // 滚动数组并打印
    move(arr, n, offset);
    print_arr(arr, n);
}

void print_arr(int array[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%4d", array[i]);
    printf("\n");
}

void move(int array[], int n, int offset)
{
    int *p, *arr_end;
    arr_end = array + n;
    int last;

    while (offset)
    {
        last = *(arr_end - 1);
        for (p = arr_end - 1; p != array; --p)
            *p = *(p - 1);
        *array = last;
        --offset;
    }
}

int z()
{
    int num[50], n, *p, j, loop, i, m, k;
    printf("请输入这一圈人的数量: \n");
    scanf("%d", &n);

    p = num;
    for (j = 0; j < n; j++)
    {
        *(p + j) = j + 1;
    }

    i = 0;
    m = 0;
    k = 0;

    while (m < n - 1)
    {
        if (*(p + i) != 0)
        {
            k++;
        }
        if (k == 3)
        {
            k = 0;
            *(p + i) = 0;
            m++;
        }
        i++;
        if (i == n)
        {
            i = 0;
        }
    }

    printf("现在剩下的人是: ");
    for (loop = 0; loop < n; loop++)
    {
        if (num[loop] != 0)
        {
            printf("%2d号\n", num[loop]);
        }
    }
}


int main()
{
    // x();
    z();

    return 0;
}
