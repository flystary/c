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
    uint8_t Index;
    void (*LedOn)(void);
    void (*LedOff)(void);
};

const static struct tagLEDFuncCB LedOpTable[] = {
    {1, LED1_On, LED1_Off},
    {0, LED2_On, LED2_Off},
    {2, LED3_On, LED3_Off}
};

void LED_Ctrl(void)
{
    static uint32_t sta = 0;
    uint8_t i = 0;

    for (i = 0; i < sizeof(LedOpTable) / sizeof(LedOpTable[0]); i++)
    {
        (sta == LedOpTable[i].Index) ? (LedOpTable[i].LedOn()) : (LedOpTable[i].LedOff());
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
}
