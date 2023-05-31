#include <stdio.h>


struct Date
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

struct Info
{
    unsigned long identifier;
    char    name[20];
    struct Date date;
    unsigned int years;
};

int main()
{
    struct Info info;
    printf("请输入学生的学号：");
    scanf("%d", &info.identifier);
    printf("请输入学生的姓名：");
    scanf("%s", info.name);
    printf("请输入学生的入学年份：");
    scanf("%d", &info.date.year);
    printf("请输入学生的入学月份：");
    scanf("%d", &info.date.month);
    printf("请输入学生的入学日期：");
    scanf("%d", &info.date.day);
    printf("请输入学生的学制：");
    scanf("%d", &info.years);

    printf("\n数据录入完毕\n\n");

    printf("学号：%d\n姓名：%s\n入学时间：%d/%d/%d\n学制：%d\n毕业时间：%d\n",\
           info.identifier, info.name,\
           info.date.year, info.date.month, info.date.day,\
           info.years, info.date.year + info.years);

    return 0;
}
