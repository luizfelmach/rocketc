#ifndef VECTOR_H
#define VECTOR_H

#include <self.h>

typedef struct _vector *Vector;
typedef void           *generic;  // Change to core // todo

Vector  vectorNew(Self self);
generic vectorAt(Vector vector, int x);
void    vectorPush(Vector vector, generic data);
int     vectorSize(Vector vector);
int     vectorIndexOf(Vector vector, generic data);
void    vectorDestroy(Vector vector);

#endif  // VECTOR_H
