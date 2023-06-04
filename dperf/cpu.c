#include "cpuload.h"

#include <stdio.h>


int main()
{
    uint32_t usage = cpuload_cal_cpusage();

    return 0;
}
