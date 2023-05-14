#include<stdio.h>
/*
// typedef 关键字，您可以使用它来为类型取一个新的名字
typedef unsigned char BYTE;

BYTE b1, b2;

typedef unsigned char byte;
*/

#include<string.h>

typedef struct Books
{
    char    title[50];
    char    author[50];
    char    subject[100];
    int     book_id;
} Book;

int print_book()
{
    Book book;

    strcpy(book.title, "C语言");
    strcpy(book.author, "baidu");
    strcpy(book.subject, "编程");
    book.book_id = 22322;

    printf( "书标题 : %s\n", book.title);
    printf( "书作者 : %s\n", book.author);
    printf( "书类目 : %s\n", book.subject);
    printf( "书 ID : %d\n", book.book_id);

    return 0;
}

/*
typedef vs #define
#define 是 C 指令，用于为各种数据类型定义别名
不同
typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。
*/


#define TRUE 1
#define FALSE 0


int print_bool()
{
    printf("----------------\n");
    printf("TRUE 的值: %d\n", TRUE);
    printf("FALSE 的值： %d\n", FALSE);

    return 0;
}


int main()
{
    print_book();

    print_bool();
}