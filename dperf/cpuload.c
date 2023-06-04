#include "cpuload.h"

#include <stdint.h>
#include <string.h>
#include <rte_common.h>
#include <rte_cycles.h>

#include "net_stats.h"

uint32_t cpuload_cal_cpusage(struct cpuload *load, uint64_t now_tsc)
{
    uint32_t usage = 0;
    uint64_t total = now_tsc - load->init_tsc;
    uint64_t work  = load->work_tsc;

    if (work <= total) {
        work  = work / 128;
        total = total / 128;
        usage = (work * 100) / total;
    } else {
        usage = 100;
    }

    load->init_tsc  = now_tsc;
    load->start_tsc = now_tsc;
    load->work_tsc  = 0;

    return usage;
}

void cpuload_init(struct cpuload *load)
{
    memset(load, 0, sizeof(struct cpuload));
    load->init_tsc = rte_rdtsc();
}
