	.text
	.file	"hello.c"
	.globl	hello_world             # -- Begin function hello_world
	.p2align	3
	.type	hello_world,@function
hello_world:                            # @hello_world
# %bb.0:
	*(u64 *)(r10 - 8) = r1
	r1 = 0
	*(u8 *)(r10 - 12) = r1
	r2 = 174353522
	*(u32 *)(r10 - 16) = r2
	r2 = 8022916924116329800 ll
	*(u64 *)(r10 - 24) = r2
	r2 = bpf_trace_printk ll
	r2 = *(u64 *)(r2 + 0)
	r3 = r10
	r3 += -24
	r4 = 12
	*(u64 *)(r10 - 32) = r1
	r1 = r3
	*(u64 *)(r10 - 40) = r2
	r2 = r4
	r3 = *(u64 *)(r10 - 40)
	callx r3
	r1 = *(u64 *)(r10 - 32)
	*(u64 *)(r10 - 48) = r0
	r0 = r1
	exit
.Lfunc_end0:
	.size	hello_world, .Lfunc_end0-hello_world
                                        # -- End function
	.type	.L__const.hello_world.msg,@object # @__const.hello_world.msg
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__const.hello_world.msg:
	.asciz	"Hello World\n"
	.size	.L__const.hello_world.msg, 13

	.type	bpf_trace_printk,@object # @bpf_trace_printk
	.data
	.p2align	3
bpf_trace_printk:
	.quad	6
	.size	bpf_trace_printk, 8

	.addrsig
	.addrsig_sym bpf_trace_printk


/*
寄存器 r1-r5：作为函数调用参数使用。在 eBPF 程序启动时，寄存器 r1 包含 "上下文" 参数指针。
寄存器 r0：存储函数的返回值，包括函数调用和当前程序退出。
寄存器 r10：eBPF程序的栈指针。
*/
