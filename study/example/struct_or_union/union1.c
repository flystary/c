#include <stdio.h>

int system_mode()
{
    union SM
    {
        int   i;
        char  c;
    };

    union SM sm;
    sm.i = 1;
    return sm.c;
}


int main()
{
    int ret;
    ret = system_mode();
    if(1==ret)
    {
        printf("小端\n");
    }
   else
    {
        printf("大端\n");
    }

    return 0;
}
