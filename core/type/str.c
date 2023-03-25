#include <metadata.h>
#include <self.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str(char *x) {
    Self str     = self_new("str");
    str->destroy = nothing;

    char *ptr = metadata_new(str, sizeof(char) * (strlen(x) + 1));
    strcpy(ptr, x);

    return ptr;
}
