#include <self.h>
#include <stdlib.h>
#include <string.h>

Self self_new(char *type_name, char *format_print) {
    Self self = (Self)calloc(1, sizeof(struct _self));
    strcpy(self->type_name, type_name);
    strcpy(self->format_print, format_print);
    return self;
}

void self_destroy(Self self) {
    free(self);
}

void self_type_name(Self self, char *type_name) {
    strcpy(self->type_name, type_name);
}

void self_format_print(Self self, char *format_print) {
    strcpy(self->format_print, format_print);
}
