#ifndef SELF_H
#define SELF_H

typedef void (*destroyFn)(void *);

struct _self {
    destroyFn destroy;
};

typedef struct _self *Self;

Self selfNew();
void selfDestroy(Self self);

#endif  // SELF_H
