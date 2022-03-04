/**
 * @brief A collection of methods for serialising and deserialising structs.
 *
 * @author Toby Godfrey
 */

///
/// Tell me of any structs for which you want methods implemented
///

#ifndef SERIALISATION_H
#define SERIALISATION_H

#include <stdint.h>

uint8_t* serialise_room(struct room room);

uint8_t* serialise_int(int num);

uint8_t* serialise_string(char* msg);

uint8_t serialise_char(char character);

uint8_t serialise_double(double num);

#endif // SERIALISATION_H
