#include "terrain_generation.h"

#include <assert.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "../log/log.h"

struct room room_init (uint8_t level, uint8_t x, uint8_t y, uint8_t z) {

  struct room room = {
    .tile_layout = {{{WALL}}},
    .level = '\0',
    .x = '\0',
    .y = '\0',
    .z = '\0',
  };

  if (x < 3 || y < 3 || z < 3) {
    clog(CAVERNA_LOG_LEVEL_ERROR, "Room too small, room initialisation failed");
  }
  else if (x > CAVERNA_LEVEL_MAX_X_DIMENSION || y > CAVERNA_LEVEL_MAX_Y_DIMENSION || z > CAVERNA_LEVEL_MAX_Z_DIMENSION) {
    clog(CAVERNA_LOG_LEVEL_ERROR, "Room larger than maximum size, room initialisation failed");
  }
  else {
    room.level = level;
    room.x = x;
    room.y = y;
    room.z = z;
    clog(CAVERNA_LOG_LEVEL_TRACE, "Room struct successfully created");
  }
  return room;
}

void generate_level(struct room *room) {
  if(room->level == '\0' || room->x == '\0' || room->y == '\0' || room->z == '\0') {
    clog(CAVERNA_LOG_LEVEL_ERROR, "Invalid room passed as parameter");
    return;
  }
  for (uint8_t x = 1; x < (room->x) - 1; x++) {
    for (uint8_t y = 1; y < (room->y) - 1; y++) {
      for (uint8_t z = 1; z < (room->z) - 1; z++) {
        room->tile_layout[x][y][z] = PATH;
      }
    }
  }
  clog(CAVERNA_LOG_LEVEL_TRACE, "Level successfully generated");
}


void prng_set_seed() {
  uint64_t prng_seed = time(0);
  srand(prng_seed);
  clogf(CAVERNA_LOG_LEVEL_TRACE, "PRNG/Room Seed: %d", prng_seed);
}

uint32_t generate_random_integer(uint32_t min, uint32_t max) {
  assert(prng_seed != '\0');
  uint32_t random_number = (rand() % (max - min + 1)) + min;
  clogf(CAVERNA_LOG_LEVEL_TRACE, "Random double: %d", random_number);
  return random_number;
}
