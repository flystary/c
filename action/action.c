#include<stdio.h>

// 局部变量
void x()
{
    int a, b;
    int c;

    a = 10;
    b = 20;
    c = a + b;

    printf("value of a = %d, b = %d and c = %d\n", a, b, c);
}

int g ;
void y()
{
    int a, b;

    a = 10;
    b = 20;
    g = a + b;
    printf("value of a = %d, b = %d and g = %d\n", a, b, g);
}

int g = 20;
void z()
{
    int g = 10;
    printf("value of g = %d\n", g);
}


// 形式参数

int a = 20;
int m()
{
    int a = 10;
    int b = 20;
    int c = 0;
    int sum(int, int);

  printf ("value of a in main() = %d\n",  a);
  c = sum( a, b);
  printf ("value of c in main() = %d\n",  c);

  return 0;
}

int sum(int a, int b)
{
    printf ("value of a in sum() = %d\n",  a);
    printf ("value of b in sum() = %d\n",  b);

    return a + b;
}


int main()
{
    // x();
    // y();
    // z();
    m();

    return 0;
}

/*

数据类型	初始化默认值
int	            0
char	       '\0'
float	        0
double	        0
pointer	       NULL
*/