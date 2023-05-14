#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, i = 0;
    char s[20];
    printf("请输入一个8进制:\n");
    gets(s);

    while (s[i] != '\0')
    {
        n = n * 8 + s[i] - '0';
        i++;
    }

    printf("转化为十进制为\n%d\n", n);

    return 0;
}