#include <node.h>
#include <stdlib.h>

Node node_new(void *value, Node next) {
    Node node   = calloc(1, sizeof(struct _node));
    node->value = value;
    node->next  = next;
    return node;
}

void node_destroy(Node node) {
    free(node);
}
