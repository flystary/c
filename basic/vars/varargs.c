#include<stdio.h>


// 可变参数

/*
int func_name(int arg1, ...);

int func(int, ... )  {
   .
   .
   .
}

int main() {
   func(2, 2, 3);
   func(3, 2, 3, 4);
}
*/

/*
stdarg.h 头文件，该文件提供了实现可变参数功能的函数和宏。具体步骤如下：

定义一个函数，最后一个参数为省略号，省略号前面可以设置自定义参数。
在函数定义中创建一个 va_list 类型变量，该类型是在 stdarg.h 头文件中定义的。
使用 int 参数和 va_start() 宏来初始化 va_list 变量为一个参数列表。宏 va_start() 是在 stdarg.h 头文件中定义的。
使用 va_arg() 宏和 va_list 变量来访问参数列表中的每个项。
使用宏 va_end() 来清理赋予 va_list 变量的内存。
常用的宏有：

va_start(ap, last_arg)：初始化可变参数列表。ap 是一个 va_list 类型的变量，last_arg 是最后一个固定参数的名称（也就是可变参数列表之前的参数）。该宏将 ap 指向可变参数列表中的第一个参数。

va_arg(ap, type)：获取可变参数列表中的下一个参数。ap 是一个 va_list 类型的变量，type 是下一个参数的类型。该宏返回类型为 type 的值，并将 ap 指向下一个参数。

va_end(ap)：结束可变参数列表的访问。ap 是一个 va_list 类型的变量。该宏将 ap 置为 NULL。
*/


#include<stdarg.h>

double average(int num, ...)
{
    va_list valist;
    double sum = 0.0;
    int i;

    va_start(valist, num);

    for (i = 0; i < num; i++) {
        sum += va_arg(valist, int);
    }
    va_end(valist);

    return sum / num ;
}

//average() 函数接受一个整数 num 和任意数量的整数参数。函数内部使用 va_list 类型的变量 va_list 来访问可变参数列表。在循环中，每次使用 va_arg() 宏获取下一个整数参数，并输出。最后，在函数结束时使用 va_end() 宏结束可变参数列表的访问。

int test()
{
    printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
    printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
    return 0;
}

int main()
{
    test();
    return 0;
}