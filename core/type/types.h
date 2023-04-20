#ifndef TYPES_H
#define TYPES_H

#define or  ||
#define and &&
#define not !

typedef enum { true = 1, false = 0 } boolean;

int    *i32(int x);
float  *f32(float x);
double *f64(double x);
char   *str(char *x, ...);

#endif