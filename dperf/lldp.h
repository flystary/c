#ifndef __LLDP_H
#define __LLDP_H

struct work_space;
void lldp_init(struct work_space *ws);
void lldp_send(struct work_space *ws);

#endif
