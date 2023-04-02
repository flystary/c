#ifdef  _HTTP_H
#define _HTTP_H

#include "data_struct.h"
extern void http_close(handle* h);
extern void http(msg* pmsg, handle* h);