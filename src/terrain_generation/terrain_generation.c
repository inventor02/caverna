#include "terrain_generation.h"

#include <stdio.h>
#include <stdlib.h>

#include "log/log.h"

struct room room_init(uint8_t level) {
  struct room room = {
    .tile_layout = {{{WALL}}},
    .level = level,
  };
  clog(CAVERNA_LOG_LEVEL_DEBUG, "room struct successfully created");
  return room;
}

void generate_level(struct room *room) {
  for(uint8_t x = 0; x < CAVERNA_LEVEL_X_DIMENSION; x++){
    for(uint8_t y = 0; y < CAVERNA_LEVEL_Y_DIMENSION; y++){
      for(uint8_t z = 0; z < CAVERNA_LEVEL_Z_DIMENSION; z++){
        clogf(CAVERNA_LOG_LEVEL_DEBUG, "[%d][%d][%d]", x, y, z);
        clogf(CAVERNA_LOG_LEVEL_DEBUG, "%d", room->tile_layout[x][y][z]);
      }
    }
  }
}
