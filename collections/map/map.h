#ifndef MAP_H
#define MAP_H

typedef struct _map *Map;

Map   map(int n, ...);
void *map_get(Map m, void *key);
void  map_set(Map m, void *key, void *value);

#endif
