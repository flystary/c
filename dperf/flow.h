#ifdef 	__FLOW_H
#define __FLOW_H


struct config;

int  flow_init(struct config *cfg);
void flow_flush(struct config *cfg);


#endif

