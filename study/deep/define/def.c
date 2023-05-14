#include<stdio.h>

#define PI 3.141592654


#include "stdio.h"

int circum(void)
{
    int r = 3;
    float s;
    s = PI*r*r;
    printf("%f\n", s);

    return 0;
}


#define IF(x) if(x){
#define ENDIF }

void def_if()
{
    IF(1)
        printf("%d\n", 1);
    ENDIF
}

// define的作用仅仅是字符串替换


// define 的坑

// #define SUM1 (a+b) (a+b) //错误
// #define SUM2(a+b) (a+b)

#define SUM3(x, y) x+y
#define SUM4(x, y) (x+y)
//记得加括号

void print_sum()
{
    int a = SUM3(2, 2)*10; //2+2*10
    printf("%d\n", a);

    int b = SUM4(2, 2)*10; //(2+2)* 10
    printf("%d\n", b);
}

// 1，防止一个头文件被重复包含

#ifndef COMDEF_H
#define COMDEF_H
//头文件内容
#endif
// 2，得到指定地址上的一个字节或字

#define MEM_B( x ) ( *( (byte *) (x) ) )
 #define MEM_W( x ) ( *( (word *) (x) ) )
// 3，求最大值和最小值

#define MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
 #define MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )
// 4，得到一个field在结构体(struct)中的偏移量

#define FPOS( type, field ) \
 /*lint -e545 */ ( (dword) &(( type *) 0)-> field ) /*lint +e545 */
// 5,得到一个结构体中field所占用的字节数

#define FSIZ( type, field ) sizeof( ((type *) 0)->field )
// 6，按照LSB格式把两个字节转化为一个Word

#define FLIPW( ray ) ( (((word) (ray)[0]) * 256) + (ray)[1] )
// 7，按照LSB格式把一个Word转化为两个字节

#define FLOPW( ray, val ) \
 (ray)[0] = ((val) / 256); \
 (ray)[1] = ((val) & 0xFF)
// 8，得到一个变量的地址（word宽度）

#define B_PTR( var ) ( (byte *) (void *) &(var) )
 #define W_PTR( var ) ( (word *) (void *) &(var) )
// 9，得到一个字的高位和低位字节

#define WORD_LO(xxx) ((byte) ((word)(xxx) & 255))
 #define WORD_HI(xxx) ((byte) ((word)(xxx) >> 8))
// 10，返回一个比X大的最接近的8的倍数

#define RND8( x ) ((((x) + 7) / 8 ) * 8 )
// 11，将一个字母转换为大写

#define UPCASE( c ) ( ((c) >= 'a' && (c) <= 'z') ? ((c) - 0x20) : (c) )
// 12，判断字符是不是10进值的数字

#define DECCHK( c ) ((c) >= '0' && (c) <= '9')
// 13，判断字符是不是16进值的数字

#define HEXCHK( c ) ( ((c) >= '0' && (c) <= '9') ||\
 ((c) >= 'A' && (c) <= 'F') ||\
 ((c) >= 'a' && (c) <= 'f') )
// 14，防止溢出的一个方法

#define INC_SAT( val ) (val = ((val)+1 > (val)) ? (val)+1 : (val))
// 15，返回数组元素的个数

#define ARR_SIZE( a ) ( sizeof( (a) ) / sizeof( (a[0]) ) )
// 16，返回一个无符号数n尾的值MOD_BY_POWER_OF_TWO(X,n)=X%(2^n)

#define MOD_BY_POWER_OF_TWO( val, mod_by ) \
 ( (dword)(val) & (dword)((mod_by)-1) )
// 17，对于IO空间映射在存储空间的结构，输入输出处理

#define inp(port) (*((volatile byte *) (port)))
 #define inpw(port) (*((volatile word *) (port)))
 #define inpdw(port) (*((volatile dword *)(port)))
 #define outp(port, val) (*((volatile byte *) (port)) = ((byte) (val)))
 #define outpw(port, val) (*((volatile word *) (port)) = ((word) (val)))
 #define outpdw(port, val) (*((volatile dword *) (port)) = ((dword) (val)))
// 18,使用一些宏跟踪调试
// A N S I标准说明了五个预定义的宏名。它们是：

_ L I N E _
 _ F I L E _
 _ D A T E _
 _ T I M E _
 _ S T D C _
// 如果编译不是标准的，则可能仅支持以上宏名中的几个，或根本不支持。记住编译程序

// 也许还提供其它预定义的宏名。

// _ L I N E _及_ F I L E _宏指令在有关# l i n e的部分中已讨论，这里讨论其余的宏名。

// _ D AT E _宏指令含有形式为月/日/年的串，表示源文件被翻译到代码时的日期。

// 源代码翻译到目标代码的时间作为串包含在_ T I M E _中。串形式为时：分：秒。

// 如果实现是标准的，则宏_ S T D C _含有十进制常量1。如果它含有任何其它数，则实现是 非标准的。

// 可以定义宏，例如:

// 当定义了_DEBUG，输出数据信息和所在文件所在行

#ifdef _DEBUG
#define DEBUGMSG(msg,date)
    printf(msg);
    printf(“%d%d%d”,date,_LINE_,_FILE_)
#else
#define DEBUGMSG(msg,date)
#endif
// 19，宏定义防止使用是错误

// 1.用小括号包含。
#define ADD(a,b) （a+b）

// 2.用do{}while(0)语句包含多语句防止错误

// 例如(错误的)：
// #define DO(a,b) a+b;\
// a++;
// 应用时：

// if(…)
// DO(a,b); //产生错误
// else
// 解决方法:

#define DO(a,b) do{a+b;\
a++;}while(0)

*/

int main()
{
    // circum();
    // def_if();

    // SUM1(1+1);
    // SUM2(1+1);

    print_sum();
}