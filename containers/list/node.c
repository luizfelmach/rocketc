#include <node.h>
#include <stdlib.h>

Node_List node_list_new(void *value, Node_List next) {
    Node_List node = calloc(1, sizeof(struct _node_list));
    node->value    = value;
    node->next     = next;
    return node;
}

void node_list_destroy(Node_List node) {
    free(node);
}
