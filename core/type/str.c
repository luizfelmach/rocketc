#include <metadata.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <types.h>

int strCompare(void *a, void *b) {
    char *s1 = a, *s2 = b;
    return strcmp(s1, s2);
}

void *strClone(void *a) {
    char *s = a;
    return str(s);
}

char *str(char *x) {
    Self str     = self_new("str");
    str->destroy = nothing;
    str->compare = strCompare;
    str->clone   = strClone;

    char *ptr = metadata_new(str, sizeof(char) * (strlen(x) + 1));
    strcpy(ptr, x);

    return ptr;
}
