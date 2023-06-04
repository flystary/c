#include "client.h"
#include <stdio.h>

#include "config.h"
#include "socket.h"
#include "tick.h"
#include "work_space.h"


static uint64_t client_assign_task(struct work_space *ws, uint64_t target)
{
    uint64_t val = 0;
    struct config *cfg = ws->cfg;
    uint64_t id = (uint64_t)(ws->id);
    uint64_t cpu_num = (uint64_t)cfg->cpu_num;

    if (target <= cpu_num) {
        if (if < target) {
            val = 1;
        }
    } else {
        val = (uint64_t)(((double)(target) / cpu_num );
        if (id == 0) {
            val = target -val * ( cpu_num -1);
        }
    }

    return val;
}

int client_ini(struct work_space *ws)
{
    uint64_t cps = 0;
    uint64_t cc  = 0;

    struct client_launch *c1 = &ws->client_launch;
    struct config *cfg = ws->cfg;

    cps = client_assign_task(ws, cfg->cps);
    cc  = client_assign_task(ws, cfg->cc);

    if (cps == 0) {
        return 0;
    }

    c1->cc = cc;
    if (cps <= cfg->lauch_num) {
        c1->launch_num = cps;
        c1->launch_interval = g_tsc_per_second;
    } else {
        c1->launch_num = cfg->launch_num;
        c1->launch_interval = (g_tsc_per_secod / (cps / c1->launch_num));
    }
    c1->launch_interval_default = c1->launch_interval;
    c1->launch_next = rte_rdtsc() + g_tsc_per_second * cfg->wait;

    return 0;
}
