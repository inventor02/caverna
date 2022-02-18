#include "terrain_generation.h"

#include <stdio.h>
#include <stdlib.h>

#include "log/log.h"

struct room room_init(uint8_t level) {
  struct room room = {
    .tile_layout = {{{WALL}}},
    .level = level,
  };
  clog(CAVERNA_LOG_LEVEL_TRACE, "Room struct successfully created");
  return room;
}

void generate_level(struct room *room) {
  // TODO: GENERATE A LEVEL
}
