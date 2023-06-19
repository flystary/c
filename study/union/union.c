#include <stdio.h>

union Job {
    float salary;
    int   workerNo;
} j;

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

int main() {
    j.workerNo = 1;
    j.salary = 12.3;
    
    printf("union 的大小 = %d 字节", sizeof(uJob));
    printf("\nstruct 的大小 = %d 字节\n", sizeof(sJob));

    printf("薪水 = %.1f\n", j.salary);
    printf("工人人数 = %d\n", j.workerNo);

    return 0;
}
