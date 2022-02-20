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

#define CAVERNA_LEVEL_MAX_X_DIMENSION 16
#define CAVERNA_LEVEL_MAX_Y_DIMENSION 16
#define CAVERNA_LEVEL_MAX_Z_DIMENSION 16

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
  enum tile_type tile_layout[CAVERNA_LEVEL_MAX_X_DIMENSION][CAVERNA_LEVEL_MAX_Y_DIMENSION][CAVERNA_LEVEL_MAX_Z_DIMENSION];
  uint8_t level;
  uint8_t min_x;
  uint8_t min_y;
  uint8_t min_z;
  uint8_t max_x;
  uint8_t max_y;
  uint8_t max_z;
};

/**
 * @brief Initialises the room.
 *
 * @param level is the level in the cave that the current room is
 * @param min_x is the minimum x dimension of the room
 * @param min_y is the minimum y dimension of the room
 * @param min_z is the minimum z dimension of the room
 * @param max_x is the maximum x dimension of the room
 * @param max_y is the maximum y dimension of the room
 * @param max_z is the maximum z dimension of the room
 */
struct room room_init(
    uint8_t level,
    uint8_t min_x,
    uint8_t min_y,
    uint8_t min_z,
    uint8_t max_x,
    uint8_t max_y,
    uint8_t max_z
    );

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
