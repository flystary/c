#include <stdint.h>
/* LED灯1亮 */
extern void LED1_On(void);

/* LED灯1灭 */
extern void LED1_Off(void);

/* LED灯2亮 */
extern void LED2_On(void);

/* LED灯2灭 */
extern void LED2_Off(void);

/* LED灯3亮 */
extern void LED3_On(void);

/* LED灯3灭 */
extern void LED3_Off(void);

/* LED灯4亮 */
extern void LED4_On(void);

/* LED灯4灭 */
extern void LED4_Off(void);

struct tagLEDFuncCB
{
    uint8_t   Index;
    uint32_t  Time;
    void (*LED_On)(void);
    void (*LED_Off)(void);
};

const static struct tagLEDFuncCB  LedOpTable[] = 
{
    {1, 10, LED1_On, LED1_Off},
    {0, 1, LED2_On, LED2_Off},
    {2, 5, LED3_On, LED3_Off},
    {3, 100, LED4_On, LED4_Off},
};

void LED_Ctrl(void)
{
    static uint32_t sta = 0;
    uint8_t i = 0;
    static uint32_t cnt = 0;
    
    if (cnt == LedOpTable[LedOpTable[sta].Index].Time)
    {
        for( i = 0; i < sizeof(LedOpTable)/sizeof(LedOpTable[0]); i++)
        {
            (sta == LedOpTable[i].Index) ? (LedOpTable[i].LED_On()) : (LedOpTable[i].LED_Off());
        }
    } else {
        //
    }

    sta++;
    cnt++;
    if (sta >= (sizeof(LedOpTable) / sizeof(LedOpTable[0])))
    {
        sta = 0;
        cnt = 0;
    }
}


int main(void)
{
    while(1)
    {
        LED_Ctrl();
        os_delay(200);
    }
}
