#include <map.h>
#include <metadata.h>
#include <pair.h>
#include <self.h>
#include <std.h>
#include <stdarg.h>
#include <stdio.h>
#include <vector.h>

struct _map {
    Vector pairs;
};

void map_destroy(void *x) {
    Map m = x;
    del(&m->pairs);
}

void map_print(void *x) {
    Map m = x;

    printf("{");

    int i;
    for (i = 0; i < len(m->pairs); i++) {
        Pair p = vector_at(m->pairs, i);
        print("{}: {}", pair_first(p), pair_second(p));
        if (i < len(m->pairs) - 1) print(", ");
    }

    printf("}");
}

Map map(int n, ...) {
    Self map = self_new("map", "");

    map->destroy = map_destroy;
    map->print   = map_print;

    Map m    = metadata_new(map, sizeof(struct _map));
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