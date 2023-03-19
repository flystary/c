#include<stdio.h>



/*
return_type function_name( parameter list )
{
   body of the function
}
*/

int max(int num1, int num2)
{
    int result;
    if (num1 > num2) {
        result = num1;
    } else {
        result = num2;
    }

    return result;
}


//
/* return_type function_name( parameter list ); */

int max1(int num1, int num2);
int max2(int, int);


int min(int num1,int num2);


int main()
{
    int a = 100;
    int b = 200;
    int ret ;
    ret = max(a, b);
    printf("Max value is : %d\n", ret);

    ret = min(a, b);
    printf("Min value is : %d\n", ret);

    return 0;
}

int min(int num1, int num2)
{
    int result;
    if (num1 < num2) {
        result = num1;
    } else {
        result = num2;
    }
    return result;
}

/*
传值调用	该方法把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数不会影响实际参数。
引用调用	通过指针传递方式，形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作。
*/