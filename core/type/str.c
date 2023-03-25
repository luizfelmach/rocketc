#include <meta.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str(char *x) {
    Self str     = selfNew("str");
    str->destroy = nothing;

    char *ptr = metaNew(str, sizeof(char) * (strlen(x) + 1));
    strcpy(ptr, x);

    return ptr;
}
