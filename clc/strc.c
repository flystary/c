#include <stdio.h>


typedef int (*Operation)(int a, int b);
typedef struct __str {
    int       result;
    Operation opt;
} STR;

int Add(int a, int b) {
    return a + b;
}


int Multi(int a, int b) {
    return a * b;
}

int main(int argc, char **argv) {
    STR str_obj;

    str_obj.opt = Add;
    str_obj.result = str_obj.opt(5, 7);
    
    printf("the result js %d\n", str_obj.result);

    str_obj.opt = Multi;
    str_obj.result = str_obj.opt(5, 7);
    
    printf("the result js %d\n", str_obj.result);

    return 0;
}
