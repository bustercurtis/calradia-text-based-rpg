#include <stdio.h>
#include <stdlib.h>
#include "structs.s"

#define MAX_CHAR_PER_TILE 4

#ifndef MAP
#define MAP

//TODO put into structs.s

typedef enum {Plain, Forest, Hills} Terrain;
typedef enum {None, Village, Castle} Structure;

typedef struct {
  Terrain terrain;
  Structure structure;
  Character characters[MAX_CHAR_PER_TILE];
} Tile;

void printMap(Tile ***map);

#endif
