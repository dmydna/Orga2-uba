#include <stddef.h>
#include <stdint.h>

typedef struct node_t {
    struct node_t *next;
    struct node_t *prev;
    char *string;
} node;

void borrarNodo(node n);