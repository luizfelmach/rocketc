#ifndef SELF_H
#define SELF_H

typedef void (*printFn)(void *);
typedef int (*compareFn)(void *, void *);
typedef void (*destroyFn)(void *);

struct _self {
    char      typeName[256];
    printFn   print;
    compareFn compare;
    destroyFn destroy;
};

typedef struct _self *Self;

Self selfNew(char *typeName);
void selfDestroy(Self self);

#endif  // SELF_H
