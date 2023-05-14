#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strconnect(char *str1, char *str2);

int str1()
{
    char str1[20], str2[20];
    char *str;
    puts("请输入两个字符串，用回车分开:");
    scanf("%s%s", str1, str2);
    str = strconnect(str1, str2);
    puts("连接后的字符串为:");
    puts(str);

    while (*str)
    {
        printf("%p\n", str);
        printf("%c\n", *str);
        str++;
    }

    return 0;
}

char *strconnect(char *str1, char *str2)
{
    char *str;
    str = (char *)malloc(strlen(str1) + strlen(str2) + 1);
    str[0] = '\0';
    strcat(str, str1);
    strcat(str, str2);
    return str;
}

int str2()
{
    int i,j,k,TLen,PLen,count=0;
    char T[50],P[10];
    printf("请输入两个字符串，以回车隔开，母串在前，子串在后：\n");
    gets(T);
    gets(P);
    TLen=strlen(T);
    PLen=strlen(P);
    for(i=0;i<=TLen-PLen;i++)
    {
        for(j=0,k=i;j<PLen&&P[j]==T[k];j++,k++)
            ;
        if(j==PLen)count++;
    }
    printf("%d\n",count);
    system("pause");
    return 0;
}
int main()
{
    // str1();
    str2();

    return 0;
}
