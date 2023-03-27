#include<stdio.h>

// 头文件
/*
#include <file>

#include "file"
*/
#include<stdio.h>

int x;
#include "header.h"

int head(void)
{
    puts (test ());

    return 0;
}

#ifndef HEADER_FILE
#define HEADER_FILE

the entire header file FILE

#endif

// 有条件引用
#if SYSTEM_1
   # include "system_1.h"
#elif SYSTEM_2
   # include "system_2.h"
#elif SYSTEM_3
   ...
#endif

 #define SYSTEM_H "system_1.h"
 ...
 #include SYSTEM_H

 //SYSTEM_H 可通过 -D 选项被您的 Makefile定义




// 在有多个 .h 文件和多个 .c 文件的时候，往往我们会用一个 global.h 的头文件来包括所有的 .h 文件，然后在除 global.h 文件外的头文件中 包含 global.h 就可以实现所有头文件的包含，同时不会乱。
#ifndef _GLOBAL_H
#define _GLOBAL_H
#include <fstream>
#include <iostream>
#include <math.h>
#include <Config.h>




// #include < > 引用的是编译器的类库路径里面的头文件。

// #include " " 引用的是你程序目录的相对路径中的头文件，如果在程序目录没有找到引用的头文件则到编译器的类库路径的目录下找该头文件。




int main(void)
{
    head();

    return 0;
}