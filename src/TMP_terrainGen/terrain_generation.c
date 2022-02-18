#include "terrain_generation.h"
#include "../log/log.h"
#include <stdio.h>
#include <stdlib.h>

struct room room_init() {
  struct room room = {
    .tile_layout = (enum tile_type*) calloc(CAVERNA_LEVEL_X_DIMENSION*CAVERNA_LEVEL_Y_DIMENSION*CAVERNA_LEVEL_Y_DIMENSION, sizeof(enum tile_type)),
    .level = -1,
  };
  clog(CAVERNA_LOG_LEVEL_DEBUG, "room struct successfully created");
  return room;
}
