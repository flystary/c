#ifndef	__HTTP_H
#define	__HTTP_H

#include <stdint.h>
#include "work_space.h"



static inline void http_parse_response(const uint8_t *data, uint16_t len)
{
	net_stats_tcp_rsp();
	
	if ((len > 9) && data[9] == '2') {
		net_stats_http_2xx();
	} else {
		net_stats_http_error();
	}
}


static inline void http_parse_request(const uint8_t *data, uint16_t len)
{
	net_stats_tcp_req();

	if ((len > 18) && data[0] == 'G') {
		net_stats_http_get();
	} else {
		net_stats_http_error();
	}
}


#define HTTP_DATA_MIN_SIZE 70
void http_set_payload(struct config *cfg, int payload_size);
const char *http_get_request(void);
const char *http_get_response(void);

#endif
