static int bpf_prog_load(union bpf_attr *attr)
{
    enum bpf_prog_type type = attr->prog_type;
    struct bpf_prog *prog;
    int err;
    ...

    // 创建 bpf_prog 对象，用于保存 eBPF 字节码和相关信息
    prog = bpf_prog_alloc(bpf_prog_size(attr->insn_cnt), GFP_USER);

    ...
    prog->len = attr->insn_cnt; // eBPF 字节码长度(也就是有多少条 eBPF 字节码)

    err = -EFAULT;
    // 把 eBPF 字节码从用户态复制到 bpf_prog 对象中
    if (copy_from_user(prog->insns, u64_to_ptr(attr->insns),
                       prog->len * sizeof(struct bpf_insn)) != 0)
        goto free_prog;

    ...
    // 这里主要找到特定模块的相关处理函数（如修正helper函数）
    err = find_prog_type(type, prog);

    // 检查 eBPF 字节码是否合法
    err = bpf_check(&prog, attr);

    // 修正helper函数的偏移量
    fixup_bpf_calls(prog);

    // 尝试将 eBPF 字节码编译成本地机器码(JIT模式)
    err = bpf_prog_select_runtime(prog);

    // 申请一个文件句柄用于与 bpf_prog 对象关联
    err = bpf_prog_new_fd(prog);

    return err;
    ...
}
