#include "log.h"

#ifdef WIN32
#include <io.h>
#include "direct.h"
#define access _access
#else
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#endif

static void nolocks_localtime(struct tm *tmp, time_t t, time_t tz, int dst);
static void nolocks_localtime_bj(struct tm *tmp, time_t t);
// static char log_path[] = "../log/";
//不同等级对应的字符串
static const char LOG_ERROR[][8] = {"Debug", "Info", "Warn", "Error", "Fatal"};

static int mkdir_parents(char *dir_path, int len)
{
    int i;
    if (!dir_path) {
        return -1;
    }
    for (i = 0; i < len; i++) {
        if (dir_path[i] == '/' && i > 0) {
            dir_path[i] = '\0';
            if (access(dir_path, 0) == -1) {
#ifdef WIN32
                _mkdir(dir_path);
#else
                mkdir(dir_path, 0755);
#endif
            }
            dir_path[i] = '/';
        }
    }
    if (len > 0 && access(dir_path, 0) == -1) {
#ifdef WIN32
        _mkdir(dir_path);
#else
        mkdir(dir_path, 0755);
#endif
    }
    return 0;
}

void Initlog(log_t *log, LOG_MODE mode, LEVEL_TYPE level, const char *path, const char *file)
{
    int len = 0;
    memset(log->log_path, 0, sizeof(log->log_path));
    memset(log->log_name, 0, sizeof(log->log_name));
    memset(log->context, 0, MAX_CONTEXT);
    log->flag     = 0;
    log->log_file = NULL;
    log->level    = level;
    if (0 < mode && mode < L_MODE_UNKNOW) {
        log->mode = mode;
    }
    else {
        log->mode = L_MODE_STD;
    }
    pthread_mutex_init(&log->mutex_log, NULL);
    // log->flag = LOG_CLOSE;
    if (!path) {
        strcpy(log->log_path, "../log/");
    }
    else {
        strcpy(log->log_path, path);
        len = strlen(log->log_path);
        if (log->log_path[len - 1] != '/') {
            log->log_path[len]     = '/';
            log->log_path[len + 1] = '\0';
        }
    }
    mkdir_parents(log->log_path, strlen(log->log_path));
    if (file) {
        strcpy(log->log_file_postfix, file);
        return;
    }
    log->flag |= LOG_DEFAULT_FILE;
}

void Destorylog(log_t *log)
{
    pthread_mutex_destroy(&log->mutex_log);
    if (log->log_file) {
        fclose(log->log_file);
        log->log_file = NULL;
    }
}

void Wlog(log_t *log, LEVEL_TYPE level, const char *format, ...)
{
    pthread_mutex_lock(&log->mutex_log);

    if (NULL == format || level < log->level) {
        pthread_mutex_unlock(&log->mutex_log);
        return;
    }
    char temp[20] = {0};

    struct tm newtime, newtime_temp;
    time_t    long_time;
    time(&long_time);
#ifdef WIN32
    localtime_s(&newtime, &long_time);
#else
    // localtime_r(&long_time, &newtime);
    nolocks_localtime_bj(&newtime, long_time);
#endif
    // newtime = localtime(&long_time);
    sprintf(temp, "%04d-%02d-%02d", newtime.tm_year + 1900, newtime.tm_mon + 1, newtime.tm_mday);

    if (log->mode == L_MODE_FILE || log->mode == L_MODE_STD_FILE) {
        if (!log->log_file) {
            strcpy(log->log_name, log->log_path);
            strcat(log->log_name, temp);
            if (LOG_FLAG_ISSET(log, LOG_DEFAULT_FILE)) {
                strcat(log->log_name, ".log");
            }
            else {
                strcat(log->log_name, "-");
                strcat(log->log_name, log->log_file_postfix);
            }
            newtime_temp         = newtime;
            newtime_temp.tm_hour = 0;
            newtime_temp.tm_min  = 0;
            newtime_temp.tm_sec  = 0;
            log->last_time       = mktime(&newtime_temp);
            log->log_file        = fopen(log->log_name, "a+");
        }

        if (long_time - log->last_time >= 86400) {
            fclose(log->log_file);
            strcpy(log->log_name, log->log_path);
            strcat(log->log_name, temp);
            if (LOG_FLAG_ISSET(log, LOG_DEFAULT_FILE)) {
                strcat(log->log_name, ".log");
            }
            else {
                strcat(log->log_name, "-");
                strcat(log->log_name, log->log_file_postfix);
            }
            log->last_time = log->last_time + 86400;
            log->log_file  = fopen(log->log_name, "a+");
        }
    }

    if (!LOG_FLAG_ISSET(log, LOG_NOTIME)) {
        sprintf(temp + strlen(temp), " %02d:%02d:%02d", newtime.tm_hour, newtime.tm_min, newtime.tm_sec);
        strcpy(log->context, "[");
        strcat(log->context, temp);
        // strcat(log->context, "][");
        // strcat(log->context, filename);
        // strcat(log->context, " ");
        // memset(temp, 0, 20);
        // sprintf(temp, "%d", line);
        // strcat(log->context, temp);

        strcat(log->context, "][");
        strcat(log->context, LOG_ERROR[level]);
        strcat(log->context, "]");
    }
    else {
        log->context[0] = '\0';
    }

    va_list argp;
    va_start(argp, format);

#ifdef WIN32
    _vsnprintf(log->context + strlen(log->context), MAX_CONTEXT - strlen(log->context), format, argp);
#else
    vsnprintf(log->context + strlen(log->context), MAX_CONTEXT - strlen(log->context), format, argp);
#endif

    va_end(argp);

    if (log->mode == L_MODE_STD || log->mode == L_MODE_STD_FILE) {
        if (level >= LEVEL_ERROR) {
            fprintf(stderr, "%s", log->context);
        }
        else {
            printf("%s", log->context);
        }
    }
    if (log->mode == L_MODE_FILE || log->mode == L_MODE_STD_FILE) {
        fprintf(log->log_file, "%s", log->context);
        fflush(log->log_file);
        if (LOG_FLAG_ISSET(log, LOG_CLOSE)) {
            fclose(log->log_file);
            log->log_file = NULL;
        }
    }
    pthread_mutex_unlock(&log->mutex_log);
}

static int is_leap_year(time_t year)
{
    if (year % 4)
        return 0; /* A year not divisible by 4 is not leap. */
    else if (year % 100)
        return 1; /* If div by 4 and not 100 is surely leap. */
    else if (year % 400)
        return 0; /* If div by 100 *and* 400 is not leap. */
    else
        return 1; /* If div by 100 and not by 400 is leap. */
}

static void nolocks_localtime(struct tm *tmp, time_t t, time_t tz, int dst)
{
    const time_t secs_min  = 60;
    const time_t secs_hour = 3600;
    const time_t secs_day  = 3600 * 24;

    t -= tz;                       /* Adjust for timezone. */
    t += 3600 * dst;               /* Adjust for daylight time. */
    time_t days    = t / secs_day; /* Days passed since epoch. */
    time_t seconds = t % secs_day; /* Remaining seconds. */

    tmp->tm_isdst = dst;
    tmp->tm_hour  = seconds / secs_hour;
    tmp->tm_min   = (seconds % secs_hour) / secs_min;
    tmp->tm_sec   = (seconds % secs_hour) % secs_min;

    /* 1/1/1970 was a Thursday, that is, day 4 from the POV of the tm structure * where sunday = 0, so to calculate the day of the week we have to add 4 * and
     * take the modulo by 7. */
    tmp->tm_wday = (days + 4) % 7;
    /* Calculate the current year. */
    tmp->tm_year = 1970;
    while (1) {
        /* Leap years have one day more. */
        time_t days_this_year = 365 + is_leap_year(tmp->tm_year);
        if (days_this_year > days) break;
        days -= days_this_year;
        tmp->tm_year++;
    }
    tmp->tm_yday = days; /* Number of day of the current year. */

    /* We need to calculate in which month and day of the month we are. To do * so we need to skip days according to how many days there are in each * month,
     * and adjust for the leap year that has one more day in February. */
    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    mdays[1] += is_leap_year(tmp->tm_year);

    tmp->tm_mon = 0;
    while (days >= mdays[tmp->tm_mon]) {
        days -= mdays[tmp->tm_mon];
        tmp->tm_mon++;
    }

    tmp->tm_mday = days + 1; /* Add 1 since our 'days' is zero-based. */
    tmp->tm_year -= 1900;    /* Surprisingly tm_year is year-1900. */
}

static void nolocks_localtime_bj(struct tm *tmp, time_t t)
{
    nolocks_localtime(tmp, t, -8 * 3600, 0);
}