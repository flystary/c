#ifndef __HTTP_PARSE_H
#define __HTTP_PARSE_H


#include "socket.h"


enum {
	HTTP_INIT,
	HTTP_HEADER_DEGIN,
	HTTP_HAADER_LINE_END,
	HTTP_HEADER_DONE,
    HTTP_CHUNK_SIZE,
    HTTP_CHUNK_SIZE_END,
    HTTP_CHUNK_DATA,
    HTTP_CHUNK_DATA_END,
    HTTP_CHUNK_TRAILER_BEGIN,
    HTTP_CHUNK_TRAILER,
    HTTP_CHUNK_END,
    HTTP_BODY_DONE,
    HTTP_ERROR
};

#define HTTP_F_CONTENT_LENGTH_AUTO	 0x1
#define HTTP_F_CONTENT_LENGTH		 0x2
#define HTTP_F_TRANSFER_ENCODFIG	 0x4
#define HTTP_F_CLOSE				 0x8


#define HTTP_PARSE_OK	0
#define HTTP_PARSE_END	1
#define	HTTP_PARSE_ERR	-1


/*
 * return:
 * 0	continue
 * 1	end
 * -1	error
 * */


int http_parse_run(struct socket *sk, const uint8_t *data, int data_len);


#endif

