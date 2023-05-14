#include<stdio.h>

/*
struct
{
    unsigned int widthValidated;
    unsigned int heightValidated;
} status;


struct
{
  unsigned int widthValidated : 1;
  unsigned int heightValidated : 1;
} status0;


struct
{
    unsigned int widthValidated;
    unsigned int heightValidated;

} status1;

struct
{
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;

} status2;


int main()
{
    printf( "Memory size occupied by status1 : %d\n", sizeof(status1));
   printf( "Memory size occupied by status2 : %d\n", sizeof(status2));

   return 0;
}

struct 位域结构名
{

 位域列表

};
*/

// type [member_name] : width ;

// type	只能为 int(整型)，unsigned int(无符号整型)，signed int(有符号整型) 三种类型，决定了如何解释位域的值。
// member_name	位域的名称。
// width	位域中位的数量。宽度必须小于或等于指定类型的位宽度。

// 带有预定义宽度的变量被称位域

struct
{
    unsigned int age : 3;
} Age;


struct bs
{
    int a:8;
    int b:2;
    int c:6;
} data;

struct packed_struct {
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int f4:1;
    unsigned int type:1;
    unsigned int my_int:9;
} pack;

#include<string.h>

struct
{
    unsigned int age : 3;
} Age;

int printAge()
{
    Age.age = 4;
    printf("Sizeof( Age ) : %d\n", sizeof(Age));
    printf("Age.age : %d\n", Age.age );

    Age.age = 7;
    printf("Age.age : %d\n", Age.age);

    Age.age = 8; // 1000
    printf("Age.age : %d\n", Age.age);

    return 0;
}


struct bs{
    unsigned a:4;
    unsigned  :4;    /* 空域 */
    unsigned b:4;    /* 从下一单元开始存放 */
    unsigned c:4
}


// a 占第一字节的 4 位，后 4 位填 0 表示不使用，b 从第二字节开始，占用 4 位，c 占用 4 位。


struct k{
    int a:1;
    int  :2;    /* 该 2 位不能使用 */
    int b:3;
    int c:2;
};

// 位域在本质上就是一种结构类型，不过其成员是按二进位分配的。


// 位域变量名.位域名
// 位域变量名->位域名

int print_bs()
{
    struct bs
    {
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    }bit, *pbit;

    bit.a = 1;
    bit.b = 7;
    bit.c = 15;

    printf("%d, %d, %d\n", bit.a, bit.b, bit.c);

    pbit = &bit;
    pbit->a=0;
    pbit->b&=3; //pbit->b=pbit->b&3 3
    pbit->c|=1; //pbit->c=pbit->c|1 15

    printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);
}

int print_bs1(){
    struct bs{
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    } bit,*pbit;
    bit.a=1;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.b=7;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.c=15;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    printf("%d,%d,%d\n",bit.a,bit.b,bit.c);    /* 以整型量格式输出三个域的内容 */
    pbit=&bit;    /* 把位域变量 bit 的地址送给指针变量 pbit */
    pbit->a=0;    /* 用指针方式给位域 a 重新赋值，赋为 0 */
    pbit->b&=3;    /* 使用了复合的位运算符 "&="，相当于：pbit->b=pbit->b&3，位域 b 中原有值为 7，与 3 作按位与运算的结果为 3（111&011=011，十进制值为 3） */
    pbit->c|=1;    /* 使用了复合位运算符"|="，相当于：pbit->c=pbit->c|1，其结果为 15 */
    printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);    /* 用指针方式输出了这三个域的值 */
}

//定义了位域结构 bs，三个位域为 a、b、c。说明了 bs 类型的变量 bit 和指向 bs 类型的指针变量 pbit。这表示位域也是可以使用指针的。

int main()
{
    // printAge();
    print_bs();
    return 0;
}
