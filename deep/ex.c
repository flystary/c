#include<stdio.h>

#define MAX_CONTEXT 10240
#define LOG_CLOSE ((int)1)
#define LOG_DEFAULT_FILE ((int)1 << 1)
#define LOG_NOTIME ((int)1 << 2)

#define LOG_SET_FLAG(log, f) ((log)->flag |= f)
#define LOG_CLEAN_FLAG(log, f) ((log)->flag &= ~f)
#define LOG_FLAG_ISSET(log, f) (((log)->flag & f) != 0)

int main()
{
    printf("%d\n", LOG_CLOSE);
    printf("%d\n", LOG_DEFAULT_FILE);
    printf("%d\n", LOG_NOTIME);
    // printf("%d\n", LOG_SET_FLAG);
    // printf("%d\n", LOG_CLEAN_FLAG);
    // printf("%d\n", LOG_FLAG_ISSET);
}