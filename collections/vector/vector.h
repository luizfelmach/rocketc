#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct _vector *Vector;

Vector vector();
void  *vector_at(Vector vector, int x);
void  *vector_front(Vector vector);
void  *vector_back(Vector vector);
void   vector_push(Vector vector, void *data);
void   vector_pop(Vector vector);
void   vector_clear(Vector vector);
int    vector_size(Vector vector);
void  *vector_find(Vector vector, void *data);
int    vector_index_of(Vector vector, void *data);
void   vector_swap(Vector vector, int a, int b);

#endif  // VECTOR_H
