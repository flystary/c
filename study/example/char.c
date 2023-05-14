#include <stdio.h>
#include <stdlib.h>

int len_c()
{
    int len;
    char str[20];
    printf("请输入字符串: \n");
    scanf("%s", str);
    // len = length(str);
    len = len_str(str);
    printf("字符串有 %d 个字符。\n", len);
}

int length(char *s)
{
    int i = 0;
    while (*s != '\0')
    {
        i++;
        s++;
    }
    return i;
}

int len_str(char *str)
{
    char *p = str;
    while (*p)
    {
        printf("%c\n", *p);
        p++;
    }

    return ((int)(p - str));
}

int z()
{
    len_c();

    return 0;
}

int my_strlen(char *str)
{
    char *p = str;
    printf("str=%s\n", str);
    printf("B: p=%p\n", p);
    while (*p++);
    printf("A: p=%p\n", p);
    return ((int)(p - str - 1));
}
/*当然也可以采用下面的写法。*/
int my_strlen_01(char *str)
{
    char *p = str;
    printf("str=%s\n", str);
    printf("B: p=%p\n", p);
    while (*p)
        p++;
    printf("A: p=%p\n", p);
    return ((int)(p - str));
}
int main()
{
    // char str[20];
    // printf("请输入字符串: ");
    // scanf("%s", str);

    // my_strlen(str);
    // my_strlen_01(str);

    z();
    /*
    while (*p++);
    当*p 为'\0'时， p仍要++, 指向'\0'下一个
    */

    return 0;
}