#include "serialisation.h"

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "../log/log.h"

uint8_t* serialise_int(int num){
  uint8_t* bitstring = calloc(sizeof(uint8_t), sizeof(num)+64);
  uint64_t timestamp = time(NULL);

  return bitstring;
}
