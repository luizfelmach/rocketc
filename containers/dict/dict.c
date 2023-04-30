#include <dict.h>
#include <mem.h>
#include <pair.h>
#include <self.h>
#include <std.h>
#include <stdarg.h>
#include <stdio.h>
#include <vector.h>

struct _dict {
    Vector data;
};

void dict_destroy(void *x) {
    Dict d = x;
    del(&d->data);
}

void dict_print(void *x) {
    Dict d = x;

    printf("{");
    int i;
    for (i = 0; i < len(d->data); i++) {
        Pair p = vector_at(d->data, i);
        print("{}: {}", pair_first(p), pair_second(p));
        if (i < len(d->data) - 1) print(", ");
    }
    printf("}");
}

int dict_len(void *x) {
    Dict d = x;
    return len(d->data);
}

void *dict_clone(void *x) {
    Dict d = x;
    Dict c = dict(0);
    del(&c->data);
    c->data = clone(d->data);
    return c;
}

Self *self_dict() {
    Self *dict = self_new("dict");

    dict->destroy = dict_destroy;
    dict->print   = dict_print;
    dict->len     = dict_len;
    dict->clone   = dict_clone;

    return dict;
}

Dict dict(int n, ...) {
    Dict m  = memory_new(self_dict(), sizeof(struct _dict));
    m->data = vector();

    va_list args;
    va_start(args, n);

    int i;
    for (i = 0; i < n; i++) {
        vector_push(m->data, va_arg(args, void *));
    }

    va_end(args);

    return m;
}

void *dict_get(Dict d, void *key) {
    void *target = NULL;

    int i;
    for (i = 0; i < len(d->data); i++) {
        Pair p = vector_at(d->data, i);
        if (!compare(key, pair_first(p))) {
            target = pair_second(p);
            break;
        }
    }

    del(&key);
    return target;
}
