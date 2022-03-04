#include "random_number_generation.h"

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "../log/log.h"

uint64_t prng_seed = 0;

void prng_set_seed() {
  if(prng_seed != 0){
    clog(CAVERNA_LOG_LEVEL_ERROR, "The PRNG has already been seeded. This should only be seeded once");
    return;
  }
  prng_seed = time(0);
  srand(prng_seed);
  clogf(CAVERNA_LOG_LEVEL_TRACE, "PRNG Seed: %d", prng_seed);
}

uint32_t generate_random_integer(uint32_t min, uint32_t max) {
  if(prng_seed == 0){
    clog(CAVERNA_LOG_LEVEL_ERROR, "The PRNG has not been seeded, this will be done automatically");
    prng_set_seed();
  }
  uint32_t random_number = (rand() % (max - min + 1)) + min;
  clogf(CAVERNA_LOG_LEVEL_TRACE, "Random integer: %d", random_number);
  return random_number;
}

double generate_random_double(){
  if(prng_seed == 0){
    clog(CAVERNA_LOG_LEVEL_ERROR, "The PRNG has not been seeded, this will be done automatically");
    prng_set_seed();
  }
  int r = rand();
  int m = RAND_MAX;
  clogf(CAVERNA_LOG_LEVEL_ERROR, "%d", r);
  clogf(CAVERNA_LOG_LEVEL_ERROR, "%d", m);
  double random_number = (double)rand()/(double)RAND_MAX;
  clogf(CAVERNA_LOG_LEVEL_TRACE, "Random double: %d", random_number);
  return random_number;
}
