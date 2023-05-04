#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int satof()
{
    float val;
    char str[20];

    strcpy(str, "98993489");
    val = atof(str);
    printf("字符串值 = %s, 浮点值 = %f\n", str, val);

    strcpy(str, "runoob");
    val = atof(str);
    printf("字符串值 = %s, 浮点值 = %f\n", str, val);

    return 0;
}

int satoi()
{
    int val;
    char str[20];

    strcpy(str, "98993489");
    val = atoi(str);
    printf("字符串值 = %s, 整型值 = %d\n", str, val);

    strcpy(str, "runoob.com");
    val = atoi(str);
    printf("字符串值 = %s, 整型值 = %d\n", str, val);

    return 0;
}

int satol()
{
    long val;
    char str[20];

    strcpy(str, "98993489");
    val = atol(str);
    printf("字符串值 = %s, 长整型值 = %ld\n", str, val);

    strcpy(str, "runoob.com");
    val = atol(str);
    printf("字符串值 = %s, 长整型值 = %ld\n", str, val);

    return 0;
}

int stod()
{
    char str[30] = "20.30300 This is test";
    char *ptr;
    double ret;

    ret = strtod(str, &ptr);
    printf("数字（double）是 %lf\n", ret);
    printf("字符串部分是 |%s|\n", ptr);

    return 0;
}

int stol()
{
    char str[30] = "2030300 This is test";
    char *ptr;
    long ret;

    ret = strtol(str, &ptr, 10);
    printf("数字（无符号长整数）是 %ld\n", ret);
    printf("字符串部分是 |%s|", ptr);
    return 0;
}

int stoul()
{
    char str[30] = "2030300 This is test";
    char *ptr;
    long ret;

    ret = strtoul(str, &ptr, 10);
    printf("数字（无符号长整数）是 %lu\n", ret);
    printf("字符串部分是 |%s|", ptr);

    return 0;
}

int main()
{
    satof();
    printf("\n");
    satoi();
    printf("\n");
    satof();
    printf("\n");
    stod();
    printf("\n");
    stol();
    printf("\n");
    stoul();
    printf("\n");

    return 0;
}