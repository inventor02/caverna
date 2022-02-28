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
  uint8_t x;
  uint8_t y;
  uint8_t z;
};

/**
 * @brief Initialises the room.
 *
 * @param level is the level in the cave that the current room is
 * @param x is the x dimension of the room
 * @param y is the y dimension of the room
 * @param z is the z dimension of the room
 */
struct room room_init(
    uint8_t level,
    uint8_t x,
    uint8_t y,
    uint8_t z
    );

/**
 * @brief The main method to generate the level and write it to the room struct.
 */
void generate_level(struct room *room);

#endif // TERRAIN_GENERATION_H
