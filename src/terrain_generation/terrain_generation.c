#include "terrain_generation.h"

#include <assert.h>
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
  uint64_t prng_seed = time(NULL);
  srand(prng_seed);
  clog(CAVERNA_LOG_LEVEL_TRACE, "PRNG has been seeded");
  clogf(CAVERNA_LOG_LEVEL_TRACE, "PRNG Seed: %d", prng_seed);
}

double generate_random_double(double min, double max) {
  assert(prng_seed != '\0');

  double random_number = (double)((rand() / RAND_MAX) * (max - min)) + min;
  clogf(CAVERNA_LOG_LEVEL_TRACE, "Random double: %d", random_number);
  return random_number;
}
