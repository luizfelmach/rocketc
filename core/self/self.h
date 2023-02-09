#ifndef SELF_H
#define SELF_H

typedef void (*printFn)(void *);
typedef void (*destroyFn)(void *);

struct _self {
    printFn   print;
    destroyFn destroy;
};

typedef struct _self *Self;

Self selfNew();
void selfDestroy(Self self);

#endif  // SELF_H
