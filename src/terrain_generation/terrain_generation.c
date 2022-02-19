#include "terrain_generation.h"

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
  uint64_t prng_seed = time(0);
  clogf(CAVERNA_LOG_LEVEL_TRACE, "PRNG Seed: %d", prng_seed);
  srand(prng_seed);
  uint64_t random_number = rand();
  clogf(CAVERNA_LOG_LEVEL_TRACE, "Random number: %d", random_number);
}
