#include <metadata.h>
#include <pair.h>
#include <self.h>
#include <std.h>

struct _pair {
    void *a, *b;
};

void pair_destroy(void *x) {
    Pair p = x;
    del(&p->a);
    del(&p->b);
}

void pair_print(void *x) {
    Pair p = x;
    print("({}, {})", p->a, p->b);
}

void *pair_clone(void *x) {
    Pair p = x;
    return pair(clone(p->a), clone(p->b));
}

int pair_compare(void *a, void *b) {
    Pair p1 = a, p2 = b;

    if (!compare(p1->a, p2->a) && !compare(p1->b, p2->b)) {
        return 0;
    }

    return 1;
}

Pair pair(void *a, void *b) {
    Self pair = self_new("pair", "");

    pair->destroy = pair_destroy;
    pair->print   = pair_print;
    pair->clone   = pair_clone;
    pair->compare = pair_compare;

    Pair p = metadata_new(pair, sizeof(struct _pair));
    p->a   = a;
    p->b   = b;

    return p;
}

void *pair_first(Pair p) {
    return p->a;
}

void *pair_second(Pair p) {
    return p->b;
}
