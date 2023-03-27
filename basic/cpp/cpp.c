#include<stdio.h>

// 预处理器
// C 预处理器（C Preprocessor）简写为 CPP 所有的预处理器命令都是以井号（#）开头。它必须是第一个非空字符，为了增强可读性，预处理器指令应从第一列开始

/*
#define	    定义宏
#include	包含一个源代码文件
#undef	    取消已定义的宏
#ifdef	    如果宏已经定义，则返回真
#ifndef	    如果宏没有定义，则返回真
#if	        如果给定条件为真，则编译下面代码
#else	    #if 的替代方案
#elif	    如果前面的 #if 给定条件不为真，当前条件为真，则编译下面代码
#endif	    结束一个 #if……#else 条件编译块
#error	    当遇到标准错误时，输出错误消息
#pragma	    使用标准化方法，向编译器发布特殊的命令到编译器中
*/

// #define Max_ARRAY_LENGTH 20  //MAX_ARRAY_LENGTH 定义为 20
// #include <stdio.h>
// #include "myheader.h"

// 从系统库中获取 stdio.h，并添加文本到当前的源文件中。下一行告诉 CPP 从本地目录中获取 myheader.h，并添加内容到当前的源文件中。

/*
#undef  FILE_SIZE
#define FILE_SIZE 42
取消已定义的 FILE_SIZE，并定义它为 42。

#ifndef MESSAGE
   #define MESSAGE "You wish!"
#endif
只有当 MESSAGE 未定义时，才定义 MESSAGE。

#ifdef DEBUG
    // Your debugging statements here
#endif
如果定义了 DEBUG，则执行处理语句。在编译时，如果您向 gcc 编译器传递了 -DDEBUG 开关量，这个指令就非常有用。它定义了 DEBUG，您可以在编译期间随时开启或关闭调试。
*/


// 预定义宏
// 可以使用不可修改
/*
__DATE__	当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
__TIME__	当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
__FILE__	这会包含当前文件名，一个字符串常量。
__LINE__	这会包含当前行号，一个十进制常量。
__STDC__	当编译器以 ANSI 标准编译时，则定义为 1。
*/

void def()
{
    printf("\n");
    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
    printf("Line :%d\n", __LINE__ );
    printf("ANSI :%d\n", __STDC__ );
}


// 预处理器运算符
// 宏延续运算符(\)
#define message_for(a, b) \
    printf(#a " and " #b ": We love you!\n")

// 字符串常量化运算符(#)
// 在宏定义中，当需要把一个宏的参数转换为字符串常量时，则使用字符串常量化运算符（#）。在宏中使用的该运算符有一个特定的参数或参数列表
#include<stdio.h>

#define message_for1(a, b) \
    printf(#a " and " #b ": We love you!\n")

int print_mess(void)
{
    message_for1(Carole, Debra);
    return 0;
}


// 标记粘贴运算符(##)
// 宏定义内的标记粘贴运算符（##）会合并两个参数。它允许在宏定义中两个独立的标记被合并为一个标记。

#define tokenpaster(n) printf("token" #n "= %d\n", token##n)

int print_mess1(void)
{
    int token34 = 40;
    tokenpaster(34);

    return 0;
}


// defined() 运算符
#if !defined (MESSAGE)
    #define MESSAGE "You wish!"
#endif

int print_mess2(void)
{
    printf("Here  is message: %s\n", MESSAGE);
    return 0;
}

// 参数化的宏
int square(int x) {
    return x * x;
}

#define square1(x) ((x) * (x))

// 在使用带有参数的宏之前，必须使用 #define 指令定义。参数列表是括在圆括号内，且必须紧跟在宏名称的后边。宏名称和左圆括号之间不允许有空格


#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(i, j) ((i) > (j) ? (j) : (i))

int print_mess3()
{
    printf("Max between 20 and 100 is %d\n", MAX(20, 100));
    printf("Min between 3.14 and 4.10 is %f\n", MIN(3.14, 4.10));

    return 0;
}


int main()
{
    // def();
    print_mess();
    print_mess1();
    print_mess2();
    print_mess3();

    return 0;
}
