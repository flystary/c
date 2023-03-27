#include<stdio.h>

//argc 是指传入参数的个数，argv[] 是一个指针数组，指向传递给程序的每个参数。

/*
int main(int argc, char *argv[])
{
    if( argc == 2)
    {
        printf("%s\n", argv[1]);
    }
    else if (argc > 2 )
    {
        printf("Too many arguments supplied.\n");
    }
    else
    {
        printf("One argument expected.\n");
    }
}
*/

int main( int argc, char *argv[] )
{
   printf("Program name %s\n", argv[0]);

   if( argc == 2 )
   {
      printf("The argument supplied is %s\n", argv[1]);
   }
   else if( argc > 2 )
   {
      printf("Too many arguments supplied.\n");
   }
   else
   {
      printf("One argument expected.\n");
   }

   return 0;
}