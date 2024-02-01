#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    int b;
    int c;
} data;

typedef void (*print_callback)(data *nums);
typedef int (*sum_callback)(data *nums);

typedef struct
{
    print_callback print;
    sum_callback sum;
} data_handler;

data_handler init_handler(print_callback print, sum_callback sum)
{
    data_handler handler;
    handler.print = print;
    handler.sum = sum;
    return handler;
}

void task(data *nums, data_handler *handler)
{
    handler->print(nums);
    printf("sum: %d\n", handler->sum(nums));
}

void print(data *nums)
{
    printf("a: %d, b: %d, c: %d\n", nums->a, nums->b, nums->c);
}

int sum(data *nums)
{
    return nums->a + nums->b + nums->c;
}

int debug_sum(data *nums)
{
    printf("debug -> a: %d\n", nums->a);
    printf("debug -> b: %d\n", nums->b);
    printf("debug -> c: %d\n", nums->c);
    return nums->a + nums->b + nums->c;
}

int main()
{
    data_handler handler = init_handler(print, sum);
    data nums = {1, 2, 3};
    task(&nums, &handler);
    // 不需要改变task函数的逻辑，只需要将handler替换成debug_handler即可

    printf("\n");
    data_handler debug_handler = init_handler(print, debug_sum);
    task(&nums, &debug_handler);
    return 0;
}
