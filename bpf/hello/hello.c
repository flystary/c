#include<linux/bpf.h>

static int (*bpf_trace_printk)(const char *fmt, int fmtsize, ...)
        = (void *)BPF_FUNC_trace_printk;

int hello_world(void *ctx)
{
    char msg[] = "Hello World\n";
    bpf_trace_printk(msg, sizeof(msg)-1);
    return 0;
}