#include <stdio.h>

void reverse(char *s)
{
    int len = 0;

    char *p = s;
    while (*p != 0)
    {
        len++;
        p++;
    }

    int i = 0;
    char c;

    while (i <= len / 2 - 1)
    {
        c = *(s + i);
        *(s + i) = *(s + len - 1 - i);
        *(s + len - 1 - i) = c;
        i++;
    }
}

int main()
{
    char s[] = "www.baidu.com";
    printf("'%s' => ", s);
    reverse(s); // 反转字符串
    printf("'%s'\n", s);
    return 0;
}