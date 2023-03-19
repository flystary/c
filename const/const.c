// // 整数常量
// /*
// 212     yes
// 215u    yes
// 0xFeeL  yes
// 078     no
// 032UU   no
// */

// 85         /* 十进制 */
// 0213       /* 八进制 */
// 0x4b       /* 十六进制 */
// 30         /* 整数 */
// 30u        /* 无符号整数 */
// 30l        /* 长整数 */
// 30ul       /* 无符号长整数 */


// int myInt = 10;
// long myLog = 100000L;
// unsigned int myUnsingnedInt = 10U;


// // 浮点常量
// 3.14159       /* 合法的 */
// 314159E-5L    /* 合法的 */
// 510E          /* 非法的：不完整的指数 */
// 210f          /* 非法的：没有小数或指数 */
// .e55          /* 非法的：缺少整数或分数 */

// float myFloat = 3.14f
// double myDoublec= 3.14159

// // 字符常量

// \\	\ 字符
// \'	' 字符
// \"	" 字符
// \?	? 字符
// \a	警报铃声
// \b	退格键
// \f	换页符
// \n	换行符
// \r	回车
// \t	水平制表符
// \v	垂直制表符
// \ooo	一到三位的八进制数
// \xhh . . .	一个或多个数字的十六进制数

// #include <stdio.h>

int hello()
{
    printf("Helo\tWorld\n\n");
    return 0;
}
/*
char myChar = 'a';
int myAsciiValue = (int) myChar; // 将 myChar 转换为 ASCII 值 97
*/

// 字符串常量

/*
"hello, dear"

"hello, \

dear"

"hello, " "d" "ear"
*/


// char myString[] = "Hello, world!";

// 定义常量
// #define identifier value


#include<stdio.h>
#define LENGTH  10
#define WIDTH   5
#define NEWLINE '\n'

int _define()
{
    int area;
    area = LENGTH * WIDTH;
    printf("value of area : %d\n", area);
    printf("%c", NEWLINE);

    return 0;
}

// const
// const type variable = value;

const int var = 8;

#include<stdio.h>
int main()
{
    const int LENGTE = 10;
    const int WIDTH  = 5;
    const char NEWLINE  = '\n';
    int area;

    area = LENGTE * WIDTH;
    printf("value of area : %d\n", area);
    printf("%c", NEWLINE);

    return 0;
}