#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct _vector *Vector;
typedef void           *generic;  // Change to core // todo

Vector  vector();
generic vector_at(Vector vector, int x);
generic vector_front(Vector vector);
generic vector_back(Vector vector);
void    vector_push(Vector vector, generic data);
void    vector_pop(Vector vector);
void    vector_clear(Vector vector);
int     vector_size(Vector vector);
generic vector_find(Vector vector, generic data);
int     vector_index_of(Vector vector, generic data);
void    vector_swap(Vector vector, int a, int b);

#endif  // VECTOR_H
