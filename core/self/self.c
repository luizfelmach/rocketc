#include <self.h>

Self selfNew() {
    Self self = (Self)calloc(1, sizeof(struct _self));
    return self;
}

void selfDestroy(Self self) {
    free(self);
}
