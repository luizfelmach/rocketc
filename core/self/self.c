#include <self.h>
#include <std.h>
#include <stdlib.h>
#include <string.h>

#define SELF_MAX 256

static int  last_self = 0;
static Self self[SELF_MAX];

Self *self_search(char *key) {
    int i;
    for (i = 0; i < last_self; i++) {
        if (!strcmp(key, self[i].key)) {
            return &self[i];
        }
    }
    return NULL;
}

void self_default(Self *s, char *key) {
    strcpy(s->key, key);
    s->destroy = nothing;
}

Self *self_new(char *key) {
    Self *s = self_search(key);

    if (!s) {
        s = &self[last_self++];
        self_default(s, key);
    }

    return s;
}
