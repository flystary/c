#ifndef DPI_NODE_H
#define DPI_NODE_H

#ifndef __cplusplus
extern "C" {
#endif
typedef struct dpi_node_t dpi_node_t, *pdpi_node_t;

struct dpi_node_t {
    int         bucket_index;
    pdpi_node_t prev;
    pdpi_node_t next;
    char        data[0];
};

#ifdef __cplusplus
}
#endif

#endif
