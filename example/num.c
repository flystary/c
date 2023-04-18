#include <stdio.h>

// 7.2.0 --->
// 7.2.3 ---> [7, 2, 3]

// 7.2.3-> [7, 2, 3]
// 7.2.3.1 [7, 2, 2, 1]

int reversed()
{
    int n, reversedNumber = 0, remainder;
    printf("输入一个整数: ");
    scanf("%d", &n);

    while (n != 0)
    {

        remainder = n % 10;
        printf("n %d %d\n", n, remainder);
        reversedNumber = reversedNumber * 10 + remainder;
        n /= 10;
        // n = n / 10;
    }

    printf("反转后的整数: %d\n", reversedNumber);

    return 0;
}

int main()
{
    reversed();
    return 0;
}