#ifndef __CPULOAD_H
#define __CPULOAD_H


#include<stdint.h>


struct cpuload {
    uint64_t init_tsc;
    uint64_t start_tsc;
    uint64_t work_tsc;
};


#define CPULOAD_ADD_TSC(load, now_tsc, work) do {
    if (work) {
        (load)->work_tsc += (now_tsc) - (load)->start_tsc;
    }
    (load)->start_tsc = (now_tsc);

    work = 0;
} while (0)

void cpuload_init(struct cpuload *load);
uint32_t cpuload_cal_cpusage(struct cpuload *load, uint64_t now_tsc);

#endif
