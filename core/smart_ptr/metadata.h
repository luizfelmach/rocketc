#ifndef META_H
#define META_H

#include <self.h>

struct _meta {
    Self  self;
    void *value;
};

typedef struct _meta *Meta;

void *metadata_new(Self s, int size);
Meta  metadata_get(void *ptr);
void  metadata_destroy(void *ptr);

#endif