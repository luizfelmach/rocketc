#include <dlist.h>
#include <node.h>
#include <self.h>
#include <std.h>
#include <stdio.h>
#include <stdlib.h>

struct _dlist {
    int        size;
    Node_DList head, tail;
};

void dlist_print(void *x) {
    DList list = x;

    Node_DList cur = list->head;

    print("[");
    while (cur) {
        print("{}", cur->value);
        if (cur->next) print(", ");
        cur = cur->next;
    }
    print("]");
}

int dlist_len(void *x) {
    DList list = x;
    return list->size;
}

void dlist_destroy(void *x) {
    DList list = x;

    Node_DList cur = list->head;
    while (cur) {
        Node_DList aux = cur->next;
        del(&cur->value);
        node_dlist_destroy(cur);
        cur = aux;
    }
}

Self *dlist_self() {
    Self *list = self_new("dlist");

    list->print   = dlist_print;
    list->destroy = dlist_destroy;
    list->len     = dlist_len;

    return list;
}

DList dlist() {
    DList dlist = memory_new(dlist_self(), sizeof(struct _dlist));

    dlist->size = 0;
    dlist->head = NULL;
    dlist->tail = NULL;

    return dlist;
}

void *dlist_front(DList dlist) {
    if (!dlist->head) return NULL;
    return dlist->head->value;
}

void *dlist_back(DList dlist) {
    if (!dlist->tail) return NULL;
    return dlist->tail->value;
}

void dlist_push_front(DList dlist, void *data) {
    Node_DList cur = dlist->head;
    dlist->head    = node_dlist_new(data, NULL, dlist->head);
    if (dlist->size == 0) {
        dlist->tail = dlist->head;
    } else {
        cur->prev = dlist->head;
    }
    dlist->size += 1;
}

void *dlist_pop_front(DList dlist) {
    if (!dlist->head) {
        printf("error: dlist is empty\n");
        exit(1);
    }
    void *data = dlist->head->value;

    Node_DList n      = dlist->head;
    dlist->head       = dlist->head->next;
    dlist->head->prev = NULL;
    node_dlist_destroy(n);

    if (dlist->size == 1) {
        dlist->tail = dlist->head;
    }
    dlist->size -= 1;

    return data;
}

void dlist_push_back(DList dlist, void *data) {
    Node_DList n = node_dlist_new(data, dlist->tail, NULL);

    if (dlist->size == 0) {
        dlist->head = dlist->tail = n;
    } else {
        dlist->tail = dlist->tail->next = n;
    }

    dlist->size += 1;
}

void *dlist_pop_back(DList dlist) {
    void *data = NULL;

    if (!dlist->head) {
        printf("error: dlist is empty\n");
        exit(1);
    }

    if (dlist->size == 1) {
        data = dlist->head->value;
        node_dlist_destroy(dlist->head);
        dlist->head = dlist->tail = NULL;
    } else {
        Node_DList penultimate = dlist->tail->prev;
        penultimate->next      = NULL;
        data                   = dlist->tail->value;
        node_dlist_destroy(dlist->tail);
        dlist->tail = penultimate;
    }

    dlist->size -= 1;

    return data;
}

void dlist_clear(DList dlist) {
    int size = dlist->size;
    int i;
    for (i = 0; i < size; i++) {
        void *data = dlist_pop_front(dlist);
        del(&data);
    }
}

void *dlist_find(DList dlist, void *data) {
    void      *target  = NULL;
    Node_DList current = dlist->head;

    while (current) {
        if (!compare(current->value, data)) {
            target = current->value;
            break;
        }
        current = current->next;
    }
    del(&data);
    return target;
}
