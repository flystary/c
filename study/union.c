#include <stdio.h>

union Job {
    float salary;
    int   workerNo;
} j;


int main() {
    j.workerNo = 1;
    j.salary = 12.3;
    
    printf("薪水 = %.1f\n", j.salary);
    printf("工人人数 = %d\n", j.workerNo);

    return 0;
}
