#include "terrain_generation.h"

#include <assert.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "log/log.h"

struct room room_init(uint8_t level) {
  struct room room = {
    .tile_layout = {{{WALL}}},
    .level = level,
  };
  clog(CAVERNA_LOG_LEVEL_TRACE, "Room struct successfully created");
  return room;
}

void generate_level(struct room *room) {
}


void prng_set_seed() {
  uint64_t prng_seed = time(0);
  srand(prng_seed);
  clog(CAVERNA_LOG_LEVEL_TRACE, "PRNG has been seeded");
  clogf(CAVERNA_LOG_LEVEL_TRACE, "PRNG Seed: %d", prng_seed);
}

uint32_t generate_random_integer(uint32_t min, uint32_t max) {
  assert(prng_seed != '\0');
  uint32_t random_number = (rand() % (max - min + 1)) + min;
  clogf(CAVERNA_LOG_LEVEL_TRACE, "Random double: %d", random_number);
  return random_number;
}
