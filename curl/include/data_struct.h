#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#ifdef __cplusplus
extern "C" {
#endif
#include "log.h"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define UNIXSOCKET_PATH_LEN_MAX 108
#define OS_PATH_LEN_MAX 256
#define ETC_FILE "./etc/curl.cfg"
#define LOG_PATH "./log"
#define SOCKET_PATH "/run/curl/"
#define SOCKET_FILENAME "curl.socket"
#define SOCKET_TARGET SOCKET_PATH SOCKET_FILENAME

// #define CPE_SN_LENGTH 64
#define URL_LEN_MAX 512
#define TOKEN_POST_DATA_LEN 256

// #define FS_NFQ_BUF_LENGTH 40960
// #define FS_NFQ_QUEUE_LENGTH 4096
// #define FS_FLOW_MAX 65536
// #define FS_HASH_BUCKET 8192
// #define FS_OUT_PUT_BUF_LENGTH 4096

#define FS_IFNAMSIZ 16
#define FS_V_IFNAMSIZ 32

typedef enum URI
{
    TOKEN      = 0,
    LOG_RECORD = 1,
} URI;

typedef struct access_token_req {
    char client_id[64];
    char client_secret[64];
    char grant_type[32];
    char password[64];
    char username[64];
} access_token_req;

typedef struct access_token_res {
    char   access_token[64];
    char   refresh_token[32];
    char   token_type[16];
    char   scope[32];
    time_t expired;
} access_token_res;

typedef struct http_req {
    void* curl;
    char  url[URL_LEN_MAX];
    int   url_len;
    int   post_data_len;
    char* post_data;
    char  res[256];
    int   res_len;
} http_req;

typedef struct curl_config {
    int              bufsize;
    int              event_max;
    int              event_size;
    int              queue_max;
    int              out_debug;
    int              response_timeout;
    LOG_MODE         log_mode;
    access_token_req token_req;
    uint64_t         cpe_id;
    char             cpe_sn[CPE_SN_LENGTH];
    char             url_prefix[URL_LEN_MAX];
    char             socketfile[UNIXSOCKET_PATH_LEN_MAX];
    log_t            slog;
    char             bin_path[OS_PATH_LEN_MAX];
    char             etc_file[OS_PATH_LEN_MAX];
    char             log_path[OS_PATH_LEN_MAX];
} curl_config;

typedef struct curl_handle {
    // dpi_chunk_t       chunk;
    // dpi_ptrring_t     ring;
    curl_config* pconfig;
    http_req      http_req[2];
    access_token_req  token_req;
    access_token_res  token_res;
    time_t            now;
    time_t            last;

    uint32_t get_token_fail;
    uint32_t chunk_alloc_fail;
    uint32_t enqueue_fail;
    uint32_t curl_init_fail;
    // uint32_t send_ips_record_fail;

    uint32_t get_token_fail_5min;
    uint32_t chunk_alloc_fail_5min;
    uint32_t enqueue_fail_5min;
    uint32_t curl_init_fail_5min;
    // uint32_t send_ips_record_fail_5min;
} curl_handle;

typedef struct alert_msg {
    char     action[8];
    uint32_t signature_id;
    char     signature[256];
} alert_msg;

typedef struct flow {
    uint32_t pkts_toserver;
    uint32_t pkts_toclient;
    uint32_t bytes_toserver;
    uint32_t bytes_toclient;
    char     start_time[32];
    char     end_time[32];
} flow;

typedef struct event {
    char      eventtime[32];
    char      event_type[16];
    char      sip[16];
    char      dip[16];
    uint16_t  sport;
    uint16_t  dport;
    char      proto[8];
    char      app_proto[8];
    alert_msg alert;
    flow      flow;
} event;

typedef struct msg {
    int  len;
    char buf[0];
} msg;

#ifdef __cplusplus
}
#endif
#endif