#include<stdio.h>
// 字符串实际上是使用空字符 \0 结尾的一维字符数组

// char site[11] = {'H','E','L','L','O','W','O','R','L','D','\0'};

// char site[] = "RUNOOB";

void echo()
{
    char site[11] = {'H','E','L','L','O','W','O','R','L','D','\0'};
    printf("echo : %s\n", site);
}
/*
strcpy(s1, s2);
复制字符串 s2 到字符串 s1。
strcat(s1, s2);
连接字符串 s2 到字符串 s1 的末尾。
strlen(s1);
返回字符串 s1 的长度。
strcmp(s1, s2);
如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
strchr(s1, ch);
返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
strstr(s1, s2);
返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。
*/


#include<string.h>

void test()
{
    char str1[14] = "baidu";
    char str2[14] = "google";
    char str3[14];
    int len ;

    strcpy(str3, str1);
    printf("strcpy(str3, str1): %s\n", str3);

    strcat(str1, str2);
    printf("strcat(str1, str2): %s\n", str1);

    len = strlen(str1);
    printf("strlen(str1): %d\n", len);
}


int main()
{
    // echo();
    test();
}