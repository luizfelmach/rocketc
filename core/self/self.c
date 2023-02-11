#include <self.h>
#include <stdlib.h>
#include <string.h>

Self selfNew(char *typeName) {
    Self self = (Self)calloc(1, sizeof(struct _self));
    strcpy(self->typeName, typeName);
    return self;
}

void selfDestroy(Self self) {
    free(self);
}
