#include <time.h>

int print()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("当前时间： %s ", asctime(timeinfo));
    return 0;
}

int interval()
{
    time_t start, end;
    int i;
    start = time(NULL);
    for (i = 0; i < 300000; i++)
    {
        printf("%d\n", i);
    }
    end = time(NULL);

    printf("时间间隔为%6.3f\n", difftime(end, start));
}

int t()
{
    long i = 10000000L;
    clock_t start, finish;
    double TheTimes;
    printf("做%ld次空循环需要的时间为", i);
    start = clock();
    while (i--);
    finish = clock();
    TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f秒。\n", TheTimes);
    return 0;
}
int main()
{
    // print();
    // interval();
    t();
    return 0;
}