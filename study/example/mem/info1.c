//Example 05
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
    char name[20];
    struct Date date;
    unsigned int years;
};

struct Info getInput(struct Info info);
void printInfo(struct Info info);

struct Info getInput(struct Info info)
{
    printf("请输入学号：");
    scanf("%d", &info.identifier);
    printf("请输入姓名：");
    scanf("%s", info.name);
    printf("请输入入学年份：");
    scanf("%d", &info.date.year);
    printf("请输入月份：");
    scanf("%d", &info.date.month);
    printf("请输入日期：");
    scanf("%d", &info.date.day);
    printf("请输入学制：");
    scanf("%d", &info.years);

    return info;
}

void printInfo(struct Info info)
{
    printf("学号：%d\n姓名：%s\n入学时间：%d/%d/%d\n学制：%d\n毕业时间：%d\n", \
        info.identifier, info.name, \
        info.date.year, info.date.month, info.date.day, \
        info.years, info.date.year + info.years);
}

int main(void)
{
    struct Info i1 = {};
    struct Info i2 = {};
    printf("请录入第一个同学的信息...\n");
    i1 = getInput(i1);
    putchar('\n');
    printf("请录入第二个学生的信息...\n");
    i2 = getInput(i2);

    printf("\n录入完毕，现在开始打印...\n\n");
    printf("打印第一个学生的信息...\n");
    printInfo(i1);
    putchar('\n');
    printf("打印第二个学生的信息...\n");
    printInfo(i2);

    return 0;
}
