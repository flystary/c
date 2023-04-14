#include <stdio.h>

void swap(int *, int *);

int x()
{
    int a, b, c;
    int *p1, *p2, *p3;

    printf("请输入 a, b, c:\n");
    scanf("%d %d %d", &a, &b, &c);

    p1 = &a;
    p2 = &b;
    p3 = &c;

    if (a > b)
        swap(p1, p2);
    if (a > c)
        swap(p1, p3);
    if (b > c)
        swap(p2, p3);

    printf("%d %d %d\n", a, b, c);

    return 0;
}

void swap(int *s1, int *s2)
{
    int t;
    t = *s1;
    *s1 = *s2;
    *s2 = t;
    // s1, s2 = s2, s1;
}

#include <stdlib.h>
void func(int *s, int n)
{
    int i;
    int max = s[0];
    int a = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] > max)
        {
            max = s[i];
            a = i;
        }
    }

    s[a] = s[a];
    s[0] = max;
    int j;
    int min = s[n - 1];
    int b = n - 1;
    for (j = 0; j < n; j++)
    {
        if (s[j] < min)
        {
            min = s[j];
            b = j;
        }
    }
    s[b] = s[n - 1];
    s[n - 1] = min;
}

void printf_s(int *s, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", s[i]);
    printf("\n");
}

int y()
{
    int s[20];
    int i, n;
    printf("设置数组长度(<20): ");
    scanf("%d", &n);

    printf("输入 %d 个元素: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);

    func(s, n);
    printf_s(s, n);

    return 0;
}

int main()
{
    // x();
    y();

    return 0;
}