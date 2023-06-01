#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Date
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};


struct Info
{
    unsigned    long identifier;
    char        name[20];
    struct      Date    date;
    unsigned    int     years;
    struct      Info*   next;
};


void addInfo(struct Info** students)
{
    struct  Info*   info, *temp;
    info = (struct Info*)malloc(sizeof(struct Info));

    if (info == NULL)
    {
        printf("内存分配失败!\n");
        exit(1);
    }

    // getInput(info);

    if (*students != NULL)
    {
        temp = *students;
        *students = info;
        info->next = temp;
    }
}

void printStu(struct Info* students)
{
    struct  Info*   info;
    int count = 1;

    info = students;

    while (info != NULL)
    {
        printf("Student%d:\n", count);
        printf("name: %s\n", info->name);
        printf("identifier: %d\n", info->identifier);
        info = info->next;

        count++;
    }
}

void releaseStu(struct Info** students)
{
    struct Info*  temp;

    while (*students != NULL)
    {
        temp = *students;
        *students = (*students)->next;
        free(temp);
    }
}

static int is_leap_year(time_t year)
{
    /*
    if (year % 4)
        return 0;
    else if (year % 100)
        return 1;
    else if (year % 400)
        return 0;
    else
        return 1;
    */

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return 0;
    else
        return 1;
}

int main()
{
    int yes;
    time_t  rawtime;
    struct tm  *tminfo; 
    
    // time(&rawtime);
    tminfo = localtime(&rawtime);

    printf("%s\n", ctime(tminfo));

    printf("tminfo: %d\n", tminfo->tm_year);
    yes = is_leap_year(tminfo->tm_year);

    
    printf("%d\n", yes);

    return 0;
}
