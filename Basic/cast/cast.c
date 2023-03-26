#include<stdio.h>

// 强制类型转换
// 强制类型转换是把变量从一种类型转换为另一种数据类型。

// (type_name) expression


int test()
{
    int sum = 17, count = 5;
    double mean;

    mean = (double) sum / count;

    printf("len: %d\n", sizeof(mean));
    printf("Value of mean: %f\n", mean);
}



// 整数提升
// 整数提升是指把小于 int 或 unsigned int 的整数类型转换为 int 或 unsigned int 的过程。

int test1()
{
    int i = 17;
    char c = 'c'; // ascii 99

    int sum = i + c;
    printf("Value of mean: %d\n", sum);
}

// 常用的算术转换
// 隐式地把值强制转换为相同的类型。编译器首先执行整数提升，如果操作数类型不同，则它们会被转换为下列层次中出现的最高层次的类型：
/*
long double
double
float
unsigned long long
long long
unsigned long
long
unsigned int
int
*/


// 常用的算术转换不适用于赋值运算符、逻辑运算符 && 和 ||。
int test2()
{
    int i = 17;
    char c = 'c'; //ascii 99

    float sum;

    sum = i + c;

    printf("Value of sum: %f\n", sum);

    return 0;
}
// c 首先被转换为整数，但是由于最后的值是 float 型的，所以会应用常用的算术转换，编译器会把 i 和 c 转换为浮点型，并把它们相加得到一个浮点数。

int main()
{
    test();
    printf("----------------------------\n");
    test1();
    printf("----------------------------\n");
    test2();

    return 0;
}