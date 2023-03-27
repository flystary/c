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


int _count1()
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

int _count2()
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


int relation()
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


// 逻辑运算符
/*
A = 1
B = 0
&&	称为逻辑与运算符。如果两个操作数都非零，则条件为真。	(A && B) 为假。
||	称为逻辑或运算符。如果两个操作数中有任意一个非零，则条件为真。	(A || B) 为真。
!	称为逻辑非运算符。用来逆转操作数的逻辑状态。如果条件为真则逻辑非运算符将使其为假。
*/


int logic()
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

/**/
#include<stdio.h>

int place()
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
/*
=	简单的赋值运算符，把右边操作数的值赋给左边操作数	C = A + B 将把 A + B 的值赋给 C
+=	加且赋值运算符，把右边操作数加上左边操作数的结果赋值给左边操作数	C += A 相当于 C = C + A
-=	减且赋值运算符，把左边操作数减去右边操作数的结果赋值给左边操作数	C -= A 相当于 C = C - A
*=	乘且赋值运算符，把右边操作数乘以左边操作数的结果赋值给左边操作数	C *= A 相当于 C = C * A
/=	除且赋值运算符，把左边操作数除以右边操作数的结果赋值给左边操作数	C /= A 相当于 C = C / A
%=	求模且赋值运算符，求两个操作数的模赋值给左边操作数	C %= A 相当于 C = C % A
<<=	左移且赋值运算符	C <<= 2 等同于 C = C << 2
>>=	右移且赋值运算符	C >>= 2 等同于 C = C >> 2
&=	按位与且赋值运算符	C &= 2 等同于 C = C & 2
^=	按位异或且赋值运算符	C ^= 2 等同于 C = C ^ 2
|=	按位或且赋值运算符	C |= 2 等同于 C = C | 2
*/

int assig()
{
   int a = 21;
   int c ;

   c = a;
   printf("c = %d\n", c);
   c += a;
   printf("c += a %d\n", c);
   c -= a;
   printf("c -= a %d\n", c);
   c *= a;
   printf("c *= a %d\n", c);
   c /= a;
   printf("c /= a %d\n", c);
   c = 200;
   c %= a;
   printf("c %%= a %d\n", c);
   c <<= 2;
   printf("c <<= 2 %d\n", c);
   c >>= 2;
   printf("c >>= 2 %d\n", c);
   c &= 2;
   printf("c &= 2 %d\n", c);
   c ^= 2;
   printf("c ^= 2 %d\n", c);
   c |= 2;
   printf("c |= 2 %d\n", c);

   return 0;
}


// 杂项运算符
/*
sizeof()	返回变量的大小。	sizeof(a) 将返回 4，其中 a 是整数。
&	返回变量的地址。	&a; 将给出变量的实际地址。
*	指向一个变量。	*a; 将指向一个变量。
? :	条件表达式	如果条件为真 ? 则值为 X : 否则值为 Y
*/

int sundry()
{
   int a = 4;
   short b;
   double c;
   int* ptr;

   printf("a size is %lu\n", sizeof(a));
   printf("b size is %lu\n", sizeof(b));
   printf("c size is %lu\n", sizeof(c));

   ptr = &a;
   printf("a is %d\n", a);
   printf("*ptr is %d\n", *ptr);

   //三元运算
   a = 10;
   b = (a == 1) ? 20: 30;
   printf("b is %d\n", b);

   b = (a == 10) ? 20: 30;
   printf("b is %d\n", b);

   return 0;
}

// C中运算符优先级
/*
后缀 	() [] -> . ++ - -  	从左到右
一元 	+ - ! ~ ++ - - (type)* & sizeof 	从右到左
乘除 	* / % 	从左到右
加减 	+ - 	从左到右
移位 	<< >> 	从左到右
关系 	< <= > >= 	从左到右
相等 	== != 	从左到右
位与 AND 	& 	从左到右
位异或 XOR 	^ 	从左到右
位或 OR 	| 	从左到右
逻辑与 AND 	&& 	从左到右
逻辑或 OR 	|| 	从左到右
条件 	?: 	从右到左
赋值 	= += -= *= /= %=>>= <<= &= ^= |= 	从右到左
逗号 	,
*/

int priority()
{
   int a = 20;
   int b = 10;
   int c = 15;
   int d = 5;
   int e;

   e = (a + b) * c / d;      // ( 30 * 15 ) / 5
   printf("(a + b) * c / d 的值是 %d\n",  e );

   e = ((a + b) * c) / d;    // (30 * 15 ) / 5
   printf("((a + b) * c) / d 的值是 %d\n" ,  e );

   e = (a + b) * (c / d);   // (30) * (15/5)
   printf("(a + b) * (c / d) 的值是 %d\n",  e );

   e = a + (b * c) / d;     //  20 + (150/5)
   printf("a + (b * c) / d 的值是 %d\n" ,  e );

   return 0;
}

int main()
{
   // assig();
   // sundry();
   priority();
   return 0;
}