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


int main()
{
    def();
}