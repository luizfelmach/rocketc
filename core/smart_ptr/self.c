#include <self.h>
#include <stdlib.h>
#include <string.h>

Self self_new(char *type_name) {
    Self self = (Self)calloc(1, sizeof(struct _self));
    strcpy(self->type_name, type_name);
    return self;
}

void self_destroy(Self self) {
    free(self);
}
