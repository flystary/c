#include <stdio.h>

int main()
{
    int a;

    printf("请输入一个数: ");
    scanf("%d", &a);

    printf("%d  %d\n", a, (a-1));

    int d = (a & (a - 1));

    if (d == 0) {
        printf("%d is 2^n\n", a);
    }else{
        printf("%d not is 2^n\n", a);
    }

    return 0;
}
