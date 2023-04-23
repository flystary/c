#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int write1()
{
    FILE *fp = NULL;
    char filename[25];
    char ch;
    printf("输入你要保存到的文件的名称：\n");
    gets(filename);
    if ((fp = fopen(filename, "w")) == NULL)
    {
        printf("error: cannot open file!\n");
        exit(0);
    }
    printf("现在你可以输入你要保存的一些字符，以#结束：\n");
    getchar();
    while ((ch = getchar()) != '#')
    {
        fputc(ch, fp);
    }
    fclose(fp);
    system("pause");
    return 0;
}

int write2()
{
    FILE *fp = NULL;
    char str[50];
    int i, len;
    printf("输入一个字符串：\n");
    gets(str);
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] <= 'z' && str[i] >= 'a')
            str[i] -= 32;
    }
    if ((fp = fopen("test", "w")) == NULL)
    {
        printf("error: cannot open file!\n");
        exit(0);
    }
    fprintf(fp, "%s\n", str);
    fclose(fp);

    system("pause");
    return 0;
}

int write3()
{
    FILE*fa,*fb,*fc;
    int i,j,k;
    char str[100],str1[100];
    char tem;
    if((fa=fopen("A.txt","r"))==NULL) // A.txt 文件需要存在
    {
        printf("error: cannot open A file!\n");
        exit(0);
    }
    fgets(str,99,fa);
    fclose(fa);
    if((fb=fopen("B.txt","r"))==NULL)  // B.txt 文件需要存在
    {
        printf("error: cannot open B file!\n");
        exit(0);
    }
    fgets(str1,100,fb);
    fclose(fb);
    strcat(str,str1);
    for(i=strlen(str)-1;i>1;i--)
        for(j=0;j<i;j++)
            if(str[j]>str[j+1])
            {
                tem=str[j];
                str[j]=str[j+1];
                str[j+1]=tem;
            }

    if((fc=fopen("C.txt","w"))==NULL)  // 合并为 C.txt
    {
        printf("error: cannot open C file!\n");
        exit(0);
    }
    fputs(str,fc);
    fclose(fc);
    // system("pause");
    return 0;
}
int main()
{
    // write1();
    // write2();
    write3();

    return 0;
}