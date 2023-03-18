#include<stdio.h>

// 算术运算符
/*
A = 10
B = 20
+	把两个操作数相加	A + B 将得到 30
-	从第一个操作数中减去第二个操作数	A - B 将得到 -10
*	把两个操作数相乘	A * B 将得到 200
/	分子除以分母	B / A 将得到 2
%	取模运算符，整除后的余数	B % A 将得到 0
++	自增运算符，整数值增加 1	A++ 将得到 11
--	自减运算符，整数值减少 1	A-- 将得到 9
*/

/*
int main()
{
    int a = 21;
    int b = 10;
    int c;

    c = a + b;
    printf("a + b = %d \n", c);
    c = a - b;
    printf("a - b = %d \n", c);
    c = a * b;
    printf("a * b = %d \n", c);
    c = a / b;
    printf("a / b = %d \n", c);
    c = a % b;
    printf("a %% b = %d \n", c);
    c = a++;
    printf("a++ = %d \n", c); //赋值后再加1
    c = a--;
    printf("a-- = %d \n", c); //赋值后再减1

    return 0;
}
*/

/*
int main()
{
    int c;
    int a = 10;
    c = a++;
    printf("先赋值后运算：\n");
    printf("c = a++ %d\n", c);
    printf("a %d\n", a);

    a = 10;
    c = a--;
    printf("c = a-- %d\n", c);
    printf("a %d\n", a);

    printf("先运算后赋值：\n");
    a = 10;
    c = ++a;
    printf("c = ++a %d\n", c);
    printf("a %d\n", a);

    a = 10;
    c = --a;
    printf("c = --a %d\n", c);
    printf("a %d\n", a);

    return  0;
}
*/

// 关系运算符
/*
A = 10
B - 20
==	检查两个操作数的值是否相等，如果相等则条件为真。	(A == B) 为假。
!=	检查两个操作数的值是否相等，如果不相等则条件为真。	(A != B) 为真。
>	检查左操作数的值是否大于右操作数的值，如果是则条件为真。	(A > B) 为假。
<	检查左操作数的值是否小于右操作数的值，如果是则条件为真。	(A < B) 为真。
>=	检查左操作数的值是否大于或等于右操作数的值，如果是则条件为真。	(A >= B) 为假。
<=	检查左操作数的值是否小于或等于右操作数的值，如果是则条件为真。	(A <= B) 为真。
*/

/*
int main()
{
   int a = 21;
   int b = 10;
   int c ;

   if( a == b )
   {
      printf("a 等于 b\n" );
   }
   else
   {
      printf("a 不等于 b\n" );
   }
   if ( a < b )
   {
      printf("a 小于 b\n" );
   }
   else
   {
      printf("a 不小于 b\n" );
   }
   if ( a > b )
   {
      printf("a 大于 b\n" );
   }
   else
   {
      printf("a 不大于 b\n" );
   }
   // 改变 a 和 b 的值
   a = 5;
   b = 20;
   if ( a <= b )
   {
      printf("a 小于或等于 b\n" );
   }
   if ( b >= a )
   {
      printf("b 大于或等于 a\n" );
   }
}
*/

// 逻辑运算符
/*
A = 1
B = 0
&&	称为逻辑与运算符。如果两个操作数都非零，则条件为真。	(A && B) 为假。
||	称为逻辑或运算符。如果两个操作数中有任意一个非零，则条件为真。	(A || B) 为真。
!	称为逻辑非运算符。用来逆转操作数的逻辑状态。如果条件为真则逻辑非运算符将使其为假。
*/
/*
#include <stdio.h>

int main()
{
   int a = 5;
   int b = 20;
   int c ;

   if ( a && b )
   {
      printf("a && b 条件为真\n" );
   }
   if ( a || b )
   {
      printf("a || b 条件为真\n" );
   }
   // 改变 a 和 b 的值
   a = 0;
   b = 10;
   if ( a && b )
   {
      printf("a && b 条件为真\n" );
   }
   else
   {
      printf("a && b 条件为假\n" );
   }
   if ( !(a && b) )
   {
      printf("!(a && b) 条件为真\n" );
   }
}
*/

// 位运算符
/*
p	q	p & q	p | q	p ^ q
0	0	  0	      0	      0
0	1	  0	      1	      1
1	1	  1	      1	      0
1	0	  0	      1	      1
*/
// A = 60 B = 13 二进制表示
/*
A = 0011 1100
B = 0000 1101
-----------------
A&B = 0000 1100
A|B = 0011 1101
A^B = 0011 0001
~A  = 1100 0011
*/
#include<stdio.h>

int main()
{
    unsigned int a = 60;    /* 60 = 0011 1100 */
    unsigned int b = 13;    /* 60 = 0000 1101  1+0+4+8*/
    int c  = 0;

    c = a & b;  // 12 = 0000 1100
    printf("a & b is %d\n", c);
    c = a | b;  // 61 = 0011 1101
    printf("a | b is %d\n", c);
    c = a ^ b;  // 49 = 0011 0001
    printf("a ^ b is %d\n", c);
    c = ~a;     //-69 = 1100 0011
    printf("~a is %d\n", c);
    c = a << 2; //240 = 1111 0000
    printf("a << 2 is %d\n", c);
    c = a >> 2; //15  = 0000 1111
    printf("a >> 2 is %d\n", c);

    return 0;
}

// 赋值运算符
// 杂项运算符