#include<stdio.h>

/*
struct tag
{
    member-list
    member-list
    member-list
}variable-list;
*/

/*
struct Books
{
    char    title[50];
    char    author[50];
    char    subject[100];
    int     book_id;
} book;


//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
//同时又声明了结构体变量s1
//这个结构体并没有标明其标签
struct
{
    int a;
    char b;
    double c;
} s1;

//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
//结构体的标签被命名为SIMPLE,没有声明变量
struct SIMPLE
{
    int a;
    char b;
    double c;
};
//用SIMPLE标签的结构体，另外声明了变量t1、t2、t3
struct SIMPLE t1, t2[20], *t3;

//也可以用typedef创建新类型
typedef struct
{
    int a;
    char b;
    double c;
} Simple2;
//现在可以用Simple2作为类型声明新的结构体变量
Simple2 u1, u2[20], *u3;


struct COMPLEX
{
    char string[100];
    struct SIMP a;
};

struct NODE
{
    char string[100];
    struct NODE *next_node;
};

struct B;

struct A
{
    struct B    *partner;
};

struct B
{
    struct A    *partner;
};

*/

//初始化
struct Books
{
    char    title[50];
    char    author[50];
    char    subject[100];
    int     book_id;
} book={ "C", "google", "编程语言", 123456 };


#include<string.h>

struct BookS
{
    char    title[50];
    char    author[50];
    char    subject[100];
    int     book_id;
};

void A()
{
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);
}

// 访问
int B()
{
    struct BookS Book1;
    struct BookS Book2;

    strcpy(Book1.title, "Rust");
    strcpy(Book1.author, "Rusts");
    strcpy(Book1.subject, "Rust开发");
    Book1.book_id = 649407;

    strcpy( Book2.author, "Zara Ali");
    strcpy( Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    printf("----------------------------------------------\n");
    printf( "Book 1 title : %s\n", Book1.title);
    printf( "Book 1 author : %s\n", Book1.author);
    printf( "Book 1 subject : %s\n", Book1.subject);
    printf( "Book 1 book_id : %d\n", Book1.book_id);

    printf("----------------------------------------------\n");
    printf( "Book 2 title : %s\n", Book2.title);
    printf( "Book 2 author : %s\n", Book2.author);
    printf( "Book 2 subject : %s\n", Book2.subject);
    printf( "Book 2 book_id : %d\n", Book2.book_id);
}

// 函数参数
struct eBooks
{
    char    title[50];
    char    author[50];
    char    subject[100];
    int     book_id;
};


void echoBook( struct eBooks book );

void echoBook( struct eBooks book )
{
    printf("-------------------------------\n");
    printf( "Book title : %s\n", book.title);
    printf( "Book author : %s\n", book.author);
    printf( "Book subject : %s\n", book.subject);
    printf( "Book book_id : %d\n", book.book_id);
}

void echo()
{
    struct eBooks Book1;        /* 声明 Book1，类型为 Books */
    struct eBooks Book2;        /* 声明 Book2，类型为 Books */

    /* Book1 详述 */
    strcpy( Book1.title, "C Programming");
    strcpy( Book1.author, "Nuha Ali");
    strcpy( Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* Book2 详述 */
    strcpy( Book2.title, "Telecom Billing");
    strcpy( Book2.author, "Zara Ali");
    strcpy( Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    /* 输出 Book1 信息 */
    echoBook( Book1 );

    /* 输出 Book2 信息 */
    echoBook( Book2 );
}

//指针
/*
struct Books *struct_pointer;

struct_pointer = &Book1;

// 为了使用指向该结构的指针访问结构的成员，您必须使用 -> 运算符
struct_pointer->title
*/

struct sBooks
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

/* 函数声明 */
void printBook( struct sBooks *book );
int print()
{
   struct sBooks Book1;        /* 声明 Book1，类型为 Books */
   struct sBooks Book2;        /* 声明 Book2，类型为 Books */

   /* Book1 详述 */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* Book2 详述 */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;

   /* 通过传 Book1 的地址来输出 Book1 信息 */
   printBook( &Book1 );

   /* 通过传 Book2 的地址来输出 Book2 信息 */
   printBook( &Book2 );

   return 0;
}

void printBook( struct sBooks *book )
{
   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}


int main()
{
    // A();
    // B();
    // echo();
    print();
}