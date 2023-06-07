#include "http.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "version.h"


#define HTTP_REQ_FORMAT         \
    "GET %s HTTP/1.1\r\n"       \
    "User-Agent: dperf\r\n"     \
    "Host: %s\r\n"              \
    "Accept: */*\r\n"           \
    "P: aa\r\n"                 \
    "\r\n"

#define HTTP_RSP_FORMAT         \
    "HTTP/1.1 200 OK\n"         \
    "Serv:dperf\n"              \
    "Content-Length:%4d\n"      \
    "Connection:keep-alive\n"   \
    "\n"                        \
    "%s"

static char http_rsp[MBUF_DATA_SIZE];
static char http_req[MBUF_DATA_SIZE];
static const char *http_rsp_body_default = "hello dperf!\r\n";

const char *http_get_request(void)
{
    return http_req;
}

const char *http_get_response(void)
{
    return http_rsp;
}

static void http_set_payload_client(struct config *cfg, char *dest, int len, int payload_size)
{
    int pad = 0;
    char buf[MBUF_DATA_SIZE] = {0};

    if (payload_size <= 0) {
        snprintf(dest, len, HTTP_REQ_FORMAT, cfg->http_path, cfg->http_host);
    } else if (payload_size < HTTP_DATA_MIN_SIZE) {
        config_set_payload(cfg, dest, payload_size, 1);
    } else {
        pad = payload_size - HTTP_DATA_MIN_SIZE;
        if (pad > 0) {
            config_set_payload(cfg, buf, pad, 0);
        }
        buf[0] = '/';
        snprintf(dest, len, HTTP_REQ_FORMAT, buf, cfg->http_host);
    }
}

static void http_set_payload_server(struct config *cfg, char *dest, int len, int payload_size)
{
    int pad = 0;
    char buf[MBUF_DATA_SIZE] = {0};
    const char *data = NULL;

    if (payload_size <= 0) {
        data = http_rsp_body_default;
        snprintf(dest, len, HTTP_RSP_FORMAT, (int)strlen(data), data);
    } else if (payload_size < HTTP_DATA_MIN_SIZE) {
        config_set_payload(cfg, dest, payload_size, 1);
    } else {
        pad = payload_size - HTTP_DATA_MIN_SIZE;
        if (pad > 0) {
            config_set_payload(cfg, buf, pad, 1);
        }
        snprintf(dest, len, HTTP_RSP_FORMAT, (int)strlen(buf), buf);
    }
}

void http_set_payload(struct config *cfg, int payload_size)
{
    http_set_payload_server(cfg, http_rsp, MBUF_DATA_SIZE, payload_size);
    http_set_payload_client(cfg, http_req, MBUF_DATA_SIZE, payload_size);
}

