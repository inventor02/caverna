/**
 * @brief A collection of methods for generating random numbers.
 *
 * @author Toby Godfrey
 */
#ifndef RANDOM_NUMBER_GENERATION_H
#define RANDOM_NUMBER_GENERATION_H

#include <stdint.h>


/**
 * @brief The seed for the PRNG. This should only be allocated once.
 */
extern uint64_t prng_seed;

/**
 * @brief A method to set the seed for the PRNG. This is to ensure the
 * seed is set only once.
 */
void prng_set_seed();

/**
 * @brief A method to generate a random integer between a given range.
 *
 * @param min is the lower bound of the range
 * @param max is the upper bound of the range
 *
 * @return a random integer between the given bounds
 */
uint32_t generate_random_integer(uint32_t min, uint32_t max);

/**
 * @brief A method to generate a random double between 0 and 1.
 *
 * @return a random double between 0 and 1
 */
double generate_random_double();

#endif // RANDOM_NUMBER_GENERATION_H
