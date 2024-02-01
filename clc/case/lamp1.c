#include <stdint.h>
#include <stdio.h>

extern void LED1_On(void);
extern void LED1_Off(void);

extern void LED2_On(void);
extern void LED2_Off(void);

extern void LED3_On(void);
extern void LED3_Off(void);

void LED_Ctrl(void)
{
    static uint32_t sta = 0;

    if (0 == sta)
    {
        LED1_On();
    } else {
        LED1_Off();
    }

    if (1 == sta)
    {
        LED2_On();
    } else {
        LED2_Off();
    }

    if (2 == sta)
    {
        LED3_On();
    } else {
        LED3_Off();
    }

    sta = (sta + 1) % 3;
}

int main(void)
{
    while(1)
    {
        LED_Ctrl();
        os_delay(200);
    }
}
