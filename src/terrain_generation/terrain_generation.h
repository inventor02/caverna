/**
 * @brief A collection of methods to generate the rouge-like rooms.
 *
 * Contains the methods required to procedurally generate rogue-like rooms.
 *
 * @author Toby Godfrey
 */

#ifndef TERRAIN_GENERATION_H
#define TERRAIN_GENERATION_H

#include <stdint.h>
#include <stdio.h>

#define CAVERNA_LEVEL_X_DIMENSION 16
#define CAVERNA_LEVEL_Y_DIMENSION 16
#define CAVERNA_LEVEL_Z_DIMENSION 16

// This can be expanded to allow for the creation of different tiles.
enum tile_type {
  WALL,
  WALL_SPECIAL,
  PATH
};

/**
 * @brief A struct to hold all the data regarding the rogue-like levels.
 */
struct room {
  enum tile_type tile_layout[CAVERNA_LEVEL_X_DIMENSION][CAVERNA_LEVEL_Y_DIMENSION][CAVERNA_LEVEL_Z_DIMENSION];
  uint8_t level;
};

/**
 * @brief Initialises the room.
 *
 * @param level is the level in the cave that the current room is
 */
struct room room_init(uint8_t level);

/**
 * @brief The main method to generate the level and write it to the room struct.
 */
void generate_level(struct room *room);

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
 * @brief A method to generate a random number between a given range.
 *
 * @param min is the lower bound of the range
 * @param max is the upper bound of the range
 *
 * @return a random double between the given bounds
 */
uint32_t generate_random_integer(uint32_t min, uint32_t max);

#endif // TERRAIN_GENERATION_H
