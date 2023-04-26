#ifndef PAIR_H
#define PAIR_H

typedef struct _pair *Pair;

Pair pair(void *a, void *b);

void *pair_first(Pair p);
void *pair_second(Pair p);

#endif