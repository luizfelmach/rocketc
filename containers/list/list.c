#include <list.h>
#include <node.h>
#include <self.h>
#include <std.h>
#include <stdio.h>
#include <stdlib.h>

struct _list {
    int       size;
    Node_List head, tail;
};

void list_print(void *x) {
    List      l = x;
    Node_List n = l->head;

    print("[");
    while (n) {
        print("{}", n->value);
        if (n->next) print(", ");
        n = n->next;
    }
    print("]");
}

int list_len(void *x) {
    List l = x;
    return l->size;
}

void list_destroy(void *x) {
    List      l = x;
    Node_List n = l->head;

    while (n) {
        Node_List aux = n->next;
        del(&n->value);
        node_list_destroy(n);
        n = aux;
    }
}

Self *list_self() {
    Self *l = self_new("list");

    l->print   = list_print;
    l->destroy = list_destroy;
    l->len     = list_len;

    return l;
}

List list() {
    List l = memory_new(list_self(), sizeof(struct _list));

    l->size = 0;
    l->head = NULL;
    l->tail = NULL;

    return l;
}

void *list_front(List l) {
    if (!l->head) {
        return NULL;
    }
    return l->head->value;
}

void *list_back(List l) {
    if (!l->tail) {
        return NULL;
    }
    return l->tail->value;
}

void list_push_front(List l, void *data) {
    Node_List n = l->head;
    l->head     = node_list_new(data, NULL, l->head);

    if (l->size == 0) {
        l->tail = l->head;
    } else {
        n->prev = l->head;
    }

    l->size += 1;
}

void *list_pop_front(List l) {
    if (!l->head) {
        printf("IndexError: pop from empty list.\n");
        exit(1);
    }

    void     *data = l->head->value;
    Node_List n    = l->head;
    l->head        = l->head->next;
    l->size -= 1;
    node_list_destroy(n);

    if (l->head) {
        l->head->prev = NULL;
    }

    if (l->size == 0) {
        l->tail = l->head;
    }

    return data;
}

void list_push_back(List l, void *data) {
    Node_List n = node_list_new(data, l->tail, NULL);

    if (l->size == 0) {
        l->head = l->tail = n;
    } else {
        l->tail = l->tail->next = n;
    }

    l->size += 1;
}

void *list_pop_back(List l) {
    if (!l->head) {
        printf("IndexError: pop from empty forward list.\n");
        exit(1);
    }

    void *data = NULL;

    if (l->size == 1) {
        data = l->head->value;
        node_list_destroy(l->head);
        l->head = l->tail = NULL;
    } else {
        Node_List penult = l->tail->prev;
        penult->next     = NULL;
        data             = l->tail->value;
        node_list_destroy(l->tail);
        l->tail = penult;
    }

    l->size -= 1;

    return data;
}

void list_clear(List l) {
    int size = l->size;
    int i;
    for (i = 0; i < size; i++) {
        void *data = list_pop_front(l);
        del(&data);
    }
}

void *list_find(List l, void *data) {
    void     *target = NULL;
    Node_List n      = l->head;

    while (n) {
        if (!compare(n->value, data)) {
            target = n->value;
            break;
        }
        n = n->next;
    }

    del(&data);

    return target;
}
