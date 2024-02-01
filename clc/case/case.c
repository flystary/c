#include <stdio.h>


typedef enum
{
    STATE_IDLE,
    STATE_RUNNING,
    STATE_STOPPED
} state_t;


typedef struct
{
    state_t state;
    void (*handler)(void);
} state_table_t;


void idle_handler(void)
{
    printf("Idle state\n");
}

void running_handler(void)
{
    printf("Runing state\n");
}

void stopped_handler(void)
{
    printf("Stopped state\n");
}

state_table_t state_table[] = {
    {STATE_IDLE, idle_handler},
    {STATE_RUNNING, running_handler},
    {STATE_STOPPED, stopped_handler}
};

int main(int argv, char *argc[])
{
    state_t current_state = STATE_IDLE;
    while (1)
    {
        state_table[current_state].handler();

        current_state = (current_state + 1) % 3;
        if (current_state == 0)
        {
           break;
        }
    }
    return 0;
}
