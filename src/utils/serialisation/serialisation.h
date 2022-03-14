/**
 * @brief A collection of methods for serialising and deserialising structs.
 *
 * @author Toby Godfrey
 */

///
/// Tell me of any structs for which you want methods implemented
///

/// The first 64 bits of the bitstring are the timestamp

#ifndef SERIALISATION_H
#define SERIALISATION_H

#include <stdint.h>

/**
  * @brief Serialise a room struct.
  *
  * @param room is the room to be serialised
  * @return a bitstring
  */
uint8_t* serialise_room(struct room room);

/**
  * @brief Serialise an integer.
  *
  * @param num is the int to be serialised
  * @return a bitstring
  */
uint8_t* serialise_int(int num);

/**
  * @brief Serialise a string.
  *
  * @param msg is the string to be serialised
  * @return a bitstring
  */
uint8_t* serialise_string(char* msg);

/**
  * @brief Serialise a character.
  *
  * @param character is the character to be serialised
  * @return a bitstring
  */
uint8_t* serialise_char(char character);

/**
  * @brief Serialise a double.
  *
  * @param num is the double to be serialised
  * @return a bitstring
  */
uint8_t* serialise_double(double num);

#endif // SERIALISATION_H
