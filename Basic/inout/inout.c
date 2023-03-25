#include<stdio.h>

// 输入&输出
/*
标准输入	stdin	键盘
标准输出	stdout	屏幕
标准错误	stderr	您的屏幕
*/
/*
%d
%f
%s
*/
int out()
{
    printf("www.baidu.com\n");
    return 0;
}

int out1()
{
    int testInteger = 5;
    printf("Number = %d\n", testInteger);
    return 0;
}

//getchar() & putchar()
/*
int getchar(void) 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。这个函数在同一个时间内只会读取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。

int putchar(int c) 函数把字符输出到屏幕上，并返回相同的字符。这个函数在同一个时间内只会输出一个单一的字符。您可以在循环内使用这个方法，以便在屏幕上输出多个字符。
*/

int get_and_put_char()
{
    int c;
    printf("Enter a Value: ");
    c = getchar();

    printf("You Entered: ");
    putchar(c);

    printf("\n");

    return 0;

}


// gets() & puts()
/*
char *gets(char *s) 函数从 stdin 读取一行到 s 所指向的缓冲区，直到一个终止符或 EOF。

int puts(const char *s) 函数把字符串 s 和一个尾随的换行符写入到 stdout。
*/

int gets_and_puts_char()
{
    char str[100];

    printf("Enter a Value: ");
    gets(str);

    printf("You Entered: ");
    puts(str);

    return 0;
}

// scanf() 和 printf()
/*
int scanf(const char *format, ...) 函数从标准输入流 stdin 读取输入，并根据提供的 format 来浏览输入。

int printf(const char *format, ...) 函数把输出写入到标准输出流 stdout ，并根据提供的格式产生输出。

format 可以是一个简单的常量字符串，但是您可以分别指定 %s、%d、%c、%f 等来输出或读取字符串、整数、字符或浮点数。
*/


int inout()
{
    char str[100];
    int i;

    printf("Enter a Value: ");
    scanf("%s %d", str, &i);

    printf("\nYou Entered: %s, %d ", str, i);
    printf("\n");

    return 0;
}

//scanf() 期待输入的格式与您给出的 %s 和 %d 相同

int main()
{
    // out();
    // out1();
    // get_and_put_char();
    // gets_and_puts_char();
    inout();
    return 0;
}