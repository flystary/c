#ifndef _HTTP_H
#define _HTTP_H

#include "data.h"
extern void http_close(ips_event_handle* h);
extern void http(event_msg* pmsg, ips_event_handle* h);
#endif
