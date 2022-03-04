#include "vector.h"

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "utils/log/log.h"

static void vector_resize(struct vector *vect) {
  // TODO implement
}

void vector_init(struct vector *vect, uint32_t capacity, uint32_t element_size) {
  assert(vect != NULL);

  clogf(CAVERNA_LOG_LEVEL_TRACE, "Initialising vector with capacity %d and element size %d.", capacity, element_size);
  *vect = (struct vector) {
    .size = 0,
    .capacity = capacity,
    .data = calloc(capacity, element_size),
    .element_size = element_size,
  };

  clog(CAVERNA_LOG_LEVEL_TRACE, "Initialised vector");
}

void vector_add(struct vector *vect, void *elem) {
  assert(vect != NULL);

  vector_resize(vect);
}

