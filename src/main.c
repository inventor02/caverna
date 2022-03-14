#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cglm/cglm.h>

#include "utils/log/log.h"
#include "utils/log/proginfo.h"
#include "render/render_master.h"
#include "terrain_generation/terrain_generation.h"
#include "utils/numbers/random_number_generation.h"
#include "utils/serialisation/serialisation.h"

int main() {
  logging_init(5);
  preamble();

  struct room room;

  room = room_init(1, 10, 10, 10);

	//run();

  uint8_t* bitstream = serialise_int(5);

  printf("Output from serialise_int: %d\n", bitstream);

  return 0;
}


