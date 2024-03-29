#include <mem.h>
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

void str_print(void *x) {
    printf("'%s'", (char *)x);
}

char *str_to_string(void *x) {
    return str((char *)x);
}

Self *str_self() {
    Self *str = self_new("str");

    str->destroy   = nothing;
    str->compare   = str_compare;
    str->clone     = str_clone;
    str->len       = str_len;
    str->print     = str_print;
    str->to_string = str_to_string;

    return str;
}

char *str(char *x, ...) {
    va_list args;
    va_start(args, x);
    int size = vsnprintf(NULL, 0, x, args);
    va_end(args);

    char *ptr = memory_new(str_self(), sizeof(char) * (size + 1));

    va_start(args, x);
    vsprintf(ptr, x, args);
    va_end(args);

    return ptr;
}
