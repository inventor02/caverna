#include "terrain_generation.h"

#include <assert.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "log/log.h"

struct room room_init (
    uint8_t level,
    uint8_t min_x,
    uint8_t min_y,
    uint8_t min_z,
    uint8_t max_x,
    uint8_t max_y,
    uint8_t max_z
    ) {

  struct room room = {
    .tile_layout = {{{WALL}}},
    .level = '\0',
    .min_x = '\0',
    .min_y = '\0',
    .min_z = '\0',
    .max_x = '\0',
    .max_y = '\0',
    .max_z = '\0',
  };

  if(max_x < min_x || max_y < min_y || max_z < min_z) {
    clog(CAVERNA_LOG_LEVEL_ERROR, "Incorrect dimension proportions, room initialisation failed");
  }
  else if (
      min_x > CAVERNA_LEVEL_MAX_X_DIMENSION ||
      min_y > CAVERNA_LEVEL_MAX_Y_DIMENSION ||
      min_z > CAVERNA_LEVEL_MAX_Z_DIMENSION ||
      max_x > CAVERNA_LEVEL_MAX_X_DIMENSION ||
      max_y > CAVERNA_LEVEL_MAX_Y_DIMENSION ||
      max_z > CAVERNA_LEVEL_MAX_Z_DIMENSION
      ) {
    clog(CAVERNA_LOG_LEVEL_ERROR, "Room larger than maximum size, room initialisation failed");
  }
  else {
    room.level = level;
    room.min_x = min_x;
    room.min_y = min_y;
    room.min_z = min_z;
    room.max_x = max_x;
    room.max_y = max_y;
    room.max_z = max_z;
    clog(CAVERNA_LOG_LEVEL_TRACE, "Room struct successfully created");
  }
  return room;
}

void generate_level(struct room *room) {
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
