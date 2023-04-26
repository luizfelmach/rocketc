#ifndef STD_H
#define STD_H

#include <mem.h>

void *clone(void *x);
int   compare(void *a, void *b);
void  del(void *x);
int   len(void *x);
void  nothing(void *ptr);
void  dump(void *x);
void  set_format_print(void *x, char *fmt);
char *format_print(void *x);
void  print(char *fmt, ...);
char *to_string(void *x);

#define or  ||
#define and &&
#define not !

typedef enum { True = 1, False = 0 } boolean;

#endif