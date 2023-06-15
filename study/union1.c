#include <stdio.h>

union unionJob
{
    char    name[32];
    float   salary;
    int     workerNo;
} uJob;

struct structJob
{
   char name[32];
   float salary;
   int workerNo;
} sJob;

int main()
{
   printf("union 的大小 = %d 字节", sizeof(uJob));
   printf("\nstruct 的大小 = %d 字节\n", sizeof(sJob));
   return 0;
}

