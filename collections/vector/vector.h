#ifndef VECTOR_H
#define VECTOR_H

#include <self.h>
#include <stdlib.h>

#define vectorFor(var, vec) \
    var = vectorAt(vec, 0); \
    for (int __i = 0; __i < vectorSize(vec); __i++, var = vectorAt(vec, __i))

typedef struct _vector *Vector;
typedef void           *generic;  // Change to core // todo

Vector  vectorNew(Self self);
generic vectorAt(Vector vector, size_t x);
generic vectorFront(Vector vector);
generic vectorBack(Vector vector);
void    vectorPush(Vector vector, generic data);
void    vectorPop(Vector vector);
void    vectorClear(Vector vector);
size_t  vectorSize(Vector vector);
generic vectorFind(Vector vector, generic data);
int     vectorIndexOf(Vector vector, generic data);
void    vectorSwap(Vector vector, size_t a, size_t b);
void    vectorDestroy(Vector vector);

#endif  // VECTOR_H
