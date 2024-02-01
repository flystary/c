#include <stdint.h>
#include <stdio.h>


extern void LED1_On(void);
extern void LED1_Off(void);
extern void LED2_On(void);
extern void LED2_Off(void);
extern void LED3_On(void);
extern void LED3_Off(void);

struct tagLEDFuncCB
{
    void (*LED_On)(void);
    void (*LED_Off)(void);
};

const static struct tagLEDFuncCB LedOpTable[] = 
{
    {LED1_On, LED1_Off},
    {LED2_On, LED2_Off},
};

void LED_Ctrl(void)
{
    static uint32_t sta = 0;
    uint8_t i;

    for (i = 0; i < sizeof(LedOpTable) / sizeof(LedOpTable[0]); i++)
    {
        (sta == i) ? (LedOpTable[i].LED_On()) : (LedOpTable[i].LED_Off());
    }
    sta = (sta + 1) % (sizeof(LedOpTable) / sizeof(LedOpTable[0]));
}

int main(void)
{
    while(1)
    {
        LED_Ctrl();
        os_delay(200);
    }

    return 0;
}
