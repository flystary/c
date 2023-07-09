#include <sys/time.h>
#include <sys/prctl.h>
#include <signal.h>
#include <sys/signalfd.h>
#include "utils.h"
#include "proc.h"
#include <sys/epoll.h>
#include <pthread.h>

int continue_flags = 1;

void *cycle_thread(void *arg)
{
    int         signal_fd, epollfd, nfds, ret;
    ssize_t     bytes;
    char        tname[32];
    struct timeval      tv, last_tv;
    struct epoll_event  ev, events[1];
    sigset_t    mask;
    struct  signalfd_siginfo info = {0};
}
