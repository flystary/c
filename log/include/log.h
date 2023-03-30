#ifndef _LOG_H
#define _LOG_H

#include<stdio.h>
#include<stdarg.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#define DY_Export_Flag
#include<pthread.h>
#define FILENAME(x) strrchr(x, '/') ? strchr(x, '/') + 1 : x

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_CONTEXT 10240
#define LOG_CLOSE ((int)1)
#define LOG_DEFAULT_FILE ((int)1 << 1)
#define LOG_NOTIME ((int)1 << 2)

#define LOG_SET_FLAG(log, f) ((log)->flag |= f)
#define LOG_CLEAN_FLAG(log, f) ((log)->flag &= ~f)
#define LOG_FLAG_ISSET(log, f) (((log)->flag & f) != 0)

/* 日志报警等级 */
typedef enum
{
    LEVEL_DEBUG = 0,  //调试,级别最低,在系统实际运行过程中一般都是不输出的
    LEVEL_INFO  = 1,  //信息,反馈系统的当前状态给最终用户的
    LEVEL_WARN  = 2,  //警告,这时进行一些修复性的工作,系统能够恢复,可以继续运行下去
    LEVEL_ERROR = 3,  //错误,导致一个无法修复的错误
    LEVEL_FATAL = 4   //致命
} LEVEL_TYPE;

typedef enum LOG_MODE
{
    L_MODE_STD      = 1,
    L_MODE_FILE     = 2,
    L_MODE_STD_FILE = 3,
    L_MODE_UNKNOW,
} LOG_MODE;

typedef struct log_t {
    char            log_path[256];
    char            log_file_postfix[256];
    char            log_name[512];
    FILE *          log_file;
    pthread_mutex_t mutex_log;
    char            context[MAX_CONTEXT];
    int             flag;
    time_t          last_time;
    LEVEL_TYPE      level;
    LOG_MODE        mode;
} log_t;

extern DY_Export_Flag void Initlog(log_t *log, LOG_MODE mode, LEVEL_TYPE level, const char *path, const char *file);
extern DY_Export_Flag void Destorylog(log_t *log);
extern DY_Export_Flag void Wlog(log_t *log, LEVEL_TYPE level, const char *format, ...);

#define LOG(log, level, format, ...) Wlog(log, level, format, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif