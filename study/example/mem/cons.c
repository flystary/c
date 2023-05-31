#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Date
{
    int year;
    int month;
    int day;
};

struct Book
{
    char title[128];
    char author[48];
    float price;
    struct Date date;
    char publisher[48];
};

void getInput(struct Book* book);//录入数据
void printBook(struct Book* book);//打印数据
void initLibrary(struct Book* lib[]);//初始化结构体
void printLibrary(struct Book* lib[]);//打印单本书数据
void releaseLibrary(struct Book* lib[]);//释放内存

void getInput(struct Book* book)
{
    printf("请输入书名：");
    scanf("%s", book->title);
    printf("请输入作者：");
    scanf("%s", book->author);
    printf("请输入售价：");
    scanf("%f", &book->price);
    printf("请输入出版日期：");
    scanf("%d-%d-%d", &book->date.year, &book->date.month, &book->date.day);
    printf("请输入出版社：");
    scanf("%s", book->publisher);
}

void printBook(struct Book* book)
{
    printf("书名：%s\n", book->title);
    printf("作者：%s\n", book->author);
    printf("售价：%.2f\n", book->price);
    printf("出版日期：%d-%d-%d\n", book->date.year, book->date.month, book->date.day);
    printf("出版社：%s\n", book->publisher);
}

void initLibrary(struct Book* lib[])
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        lib[i] = NULL;
    }
}

void printLibrary(struct Book* lib[])
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (lib[i] != NULL)
        {
            printBook(lib[i]);
            putchar('\n');
        }
    }
}

void releaseLibrary(struct Book* lib[])
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (lib[i] != NULL)
        {
            free(lib[i]);
        }
    }
}

int main(void)
{
    struct Book* lib[MAX_SIZE];
    struct Book* p = NULL;
    int ch, index = 0;

    initLibrary(lib);

    while (1)
    {
        printf("请问是否要录入图书信息(Y/N):");
        do
        {
            ch = getchar();
        } while (ch != 'Y' && ch != 'N');

        if (ch == 'Y')
        {
            if (index < MAX_SIZE)
            {
                p = (struct Book*)malloc(sizeof(struct Book));
                getInput(p);
                lib[index] = p;
                index++;
                putchar('\n');
            }
            else
            {
                printf("数据库已满！\n");
                break;
            }
        }
        else
        {
            break;
        }
    }

    printf("\n数据录入完毕，开始打印验证...\n\n");
    printLibrary(lib);
    releaseLibrary(lib);

    return 0;
}
