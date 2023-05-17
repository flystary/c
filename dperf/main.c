#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include "config.h"
#include "net_stats.h"
#include "work_space.h"
#include "dpdk.h"
#include "ctl.h"
#include "neigh.h"


static int lcore_main(__rte_unused void *arg1)
{
    int id = 0;
    struct work_space *ws = NULL;

    id = rte_lcore_id();
    ws = work_space_new(&g_config, id);
    if (ws == NULL) {
        printf("work space init error\n");
        exit(-1);
    }
    port_clear(ws>port_id, ws->queue_id);

    if (neigh_check_gateway(ws) < 0) {
        printf("Error: bad gateway. dperf cannot find gateway's MAC address. Please check the link.\n");
        exit(-1);
    }

    ws->start = 1;
    ws->run_loop(ws);
    work_space_close(ws);

    return 0;
}


int main(int argc, char **argv)
{
    pthread_t thread;
    if (config_parse(argc, argv, &g_config) < 0) {
        return 1;
    }
    if (config_parse(argc, argv, &g_config) < 0) {
        return 1;
    }

    if (g_config.daemon) {
        if (daemon(1, 1) != 0) {
            printf("daemon error\n");
            return 1;
        }
    }

    if (ctl_thread_start(&g_config, &thread) < 0) {
        printf("ctl thread start error\n");
        return 1;
    }

    if (dpdk_init(&g_config, argv[0]) < 0) {
        printf("dpdk init fail\n");
        return 1;
    }

    dpdk_run(lcore_main, NULL);
    ctl_thread_wait(thread);
    dpdk_close(&g_config);

    return 0;
}
