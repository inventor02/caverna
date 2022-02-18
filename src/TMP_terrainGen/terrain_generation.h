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

#define CAVERNA_LEVEL_X_DIMENSION 255
#define CAVERNA_LEVEL_Y_DIMENSION 255
#define CAVERNA_LEVEL_Z_DIMENSION 255

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
  enum tile_type* tile_layout;
  uint8_t level;
};

/**
 * @brief Initialises the terrain generation.
 */
struct room room_init();

/**
 * @brief The main method to generate the level and write it to the room struct.
 */
void generate_level(struct room *room);

#endif // TERRAIN_GENERATION_H
