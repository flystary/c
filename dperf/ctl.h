#ifndef __CTL_H
#define __CTL_H


#include <pthread.h>
#include "config.h"


int  ctl_thread_start(struct config *cfg, pthread_t *thread);
void ctl_thread_wait(pthread_t thread);

#endif
