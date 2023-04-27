#include <list.h>
#include <mem.h>
#include <node.h>
#include <self.h>
#include <std.h>

struct _list {
    int  size;
    Node head, tail;
};

void list_print(void *x) {
    List list = x;

    Node cur = list->head;

    print("[");
    while (cur) {
        print("{}", cur->value);
        if (cur->next) print(", ");
        cur = cur->next;
    }
    print("]");
}

int list_len(void *x) {
    List list = x;
    return list->size;
}

void list_destroy(void *x) {
    List list = x;

    Node cur = list->head;
    while (cur) {
        Node aux = cur->next;
        del(&cur->value);
        node_destroy(cur);
        cur = aux;
    }
}

Self *list_self() {
    Self *list = self_new("list");

    list->print   = list_print;
    list->destroy = list_destroy;
    list->len     = list_len;

    return list;
}

List list() {
    List list = memory_new(list_self(), sizeof(struct _list));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void *list_front(List list) {
    if (!list->head) return NULL;
    return list->head->value;
}

void *list_back(List list) {
    if (!list->tail) return NULL;
    return list->tail->value;
}

void list_push_front(List list, void *data) {
    Node new_node = node_new(data, list->head);

    if (list->size == 0) {
        list->tail = new_node;
    }

    list->head = new_node;

    list->size += 1;
}

void *list_pop_front(List list) {
    if (list->size == 0) {
        return NULL;
    }

    if (list->size == 1) {
        list->tail = NULL;
    }

    void *value = list->head->value;

    Node cur_head = list->head;

    list->head = list->head->next;
    node_destroy(cur_head);

    list->size -= 1;

    return value;
}

void list_push_back(List list, void *data) {
    Node new_node = node_new(data, NULL);

    if (list->size == 0) {
        list->tail = list->head = new_node;
    } else {
        list->tail = list->tail->next = new_node;
    }

    list->size += 1;
}

void *list_pop_back(List list) {
    return NULL;
}

void list_clear(List list) {
    int size = list->size;
    int i;
    for (i = 0; i < size; i++) {
        void *value = list_pop_front(list);
        del(&value);
    }
}

void *list_find(List list, void *data) {
    void *target = NULL;
    Node  cur    = list->head;

    while (cur) {
        if (!compare(cur->value, data)) {
            target = cur->value;
            break;
        }
        cur = cur->next;
    }
    del(&data);

    return target;
}
