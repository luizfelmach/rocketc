#include <dict.h>
#include <mem.h>
#include <pair.h>
#include <self.h>
#include <std.h>
#include <stdarg.h>
#include <stdio.h>
#include <vector.h>

struct _dict {
    Vector pairs;
};

void dict_destroy(void *x) {
    Dict d = x;
    del(&d->pairs);
}

void dict_print(void *x) {
    Dict d = x;

    printf("{");
    int i;
    for (i = 0; i < len(d->pairs); i++) {
        Pair p = vector_at(d->pairs, i);
        print("{}: {}", pair_first(p), pair_second(p));
        if (i < len(d->pairs) - 1) print(", ");
    }
    printf("}");
}

int dict_len(void *x) {
    Dict d = x;
    return len(d->pairs);
}

void *dict_clone(void *x) {
    Dict d = x;
    Dict c = dict(0);
    del(&c->pairs);
    c->pairs = clone(d->pairs);
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
    Dict m   = memory_new(self_dict(), sizeof(struct _dict));
    m->pairs = vector();

    va_list args;
    va_start(args, n);

    int i;
    for (i = 0; i < n; i++) {
        vector_push(m->pairs, va_arg(args, void *));
    }

    va_end(args);

    return m;
}

void *dict_get(Dict d, void *key) {
    void *target = NULL;

    int i;
    for (i = 0; i < len(d->pairs); i++) {
        Pair p = vector_at(d->pairs, i);
        if (!compare(key, pair_first(p))) {
            target = pair_second(p);
            break;
        }
    }

    del(&key);
    return target;
}
