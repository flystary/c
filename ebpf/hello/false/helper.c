enum bpf_func_id {
    BPF_FUNC_unspec,               // 0
    BPF_FUNC_map_lookup_elem,      // 1
    BPF_FUNC_map_update_elem,      // 2
    BPF_FUNC_map_delete_elem,      // 3
    BPF_FUNC_probe_read,           // 4
    BPF_FUNC_ktime_get_ns,         // 5
    BPF_FUNC_trace_printk,         // 6
    BPF_FUNC_get_prandom_u32,      // 7
    BPF_FUNC_get_smp_processor_id, // 8
    BPF_FUNC_skb_store_bytes,      // 9
    BPF_FUNC_l3_csum_replace,      // 10
    BPF_FUNC_l4_csum_replace,      // 11
    BPF_FUNC_tail_call,            // 12
    BPF_FUNC_clone_redirect,       // 13
    BPF_FUNC_get_current_pid_tgid, // 14
    BPF_FUNC_get_current_uid_gid,  // 15
    ...
    __BPF_FUNC_MAX_ID,
};

#include <linux/bpf.h>

// 声明要调用的helper函数为：BPF_FUNC_trace_printk
static int (*bpf_trace_printk)(const char *fmt, int fmtsize, ...)
        = (void *)BPF_FUNC_trace_printk;

int hello_world(void *ctx)
{
    char msg[] = "Hello World\n";
    
    // 调用helper函数
    bpf_trace_printk(msg, sizeof(msg)-1);
    return 0;
}

static void fixup_bpf_calls(struct bpf_prog *prog)
{
    const struct bpf_func_proto *fn;
    int i;

    // 遍历所有的 eBPF 字节码
    for (i = 0; i < prog->len; i++) {
        struct bpf_insn *insn = &prog->insnsi[i];

        // 如果是函数调用指令
        if (insn->code == (BPF_JMP | BPF_CALL)) {
            ...
            // 通过 helper 函数的编号获取其真实地址
            fn = prog->aux->ops->get_func_proto(insn->imm);
            
            ...
            // 由于 bpf_insn 结构的 imm 字段类型为 int，
            // 为了能够将 helper 函数的地址（64位）保存到一个 int 中，
            // 所以减去一个基础函数地址，调用的时候加上这个基础函数地址即可。
            insn->imm = fn->func - __bpf_call_base;
        }
    }
}

setsockopt(sock, SOL_SOCKET, SO_ATTACH_BPF, &prog_fd, sizeof(prog_fd));

// file: net/packet/af_packet.c

static int 
packet_rcv(struct sk_buff *skb, 
           struct net_device *dev, 
           struct packet_type *pt, 
           struct net_device *orig_dev)
{
    ...
    // 执行 eBPF 程序
    res = run_filter(skb, sk, snaplen);
    if (!res)
        goto drop_n_restore;
    ...
}
