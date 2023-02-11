#ifndef VECTOR_H
#define VECTOR_H

#include <self.h>

typedef struct _vector *Vector;
typedef void           *generic;  // Change to core // todo

Vector  vectorNew(Self self);
generic vectorAt(Vector vector, int x);
generic vectorFront(Vector vector);
generic vectorBack(Vector vector);
void    vectorPush(Vector vector, generic data);
void    vectorPop(Vector vector);
void    vectorClear(Vector vector);
int     vectorSize(Vector vector);
generic vectorFind(Vector vector, generic data);
int     vectorIndexOf(Vector vector, generic data);
void    vectorShow(Vector vector);
void    vectorDestroy(Vector vector);

#endif  // VECTOR_H
