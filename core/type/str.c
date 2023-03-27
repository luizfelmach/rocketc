#include <metadata.h>
#include <self.h>
#include <std.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <types.h>

int str_compare(void *a, void *b) {
    char *s1 = a, *s2 = b;
    return strcmp(s1, s2);
}

void *str_clone(void *a) {
    char *s = a;
    return str(s);
}

int str_len(void *x) {
    return strlen(x);
}

char *str(char *x, ...) {
    Self str     = self_new("str");
    str->destroy = nothing;
    str->compare = str_compare;
    str->clone   = str_clone;
    str->len     = str_len;

    va_list args;
    va_start(args, x);
    int size = vsnprintf(NULL, 0, x, args);
    va_end(args);

    char *ptr = metadata_new(str, sizeof(char) * (size + 1));

    va_start(args, x);
    vsprintf(ptr, x, args);
    va_end(args);

    return ptr;
}
