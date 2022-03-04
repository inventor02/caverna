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

int main() {
  logging_init(5);
  preamble();

  struct room room;

  clogf(CAVERNA_LOG_LEVEL_ERROR, "Sizeof(room struct) bytes before = %d", sizeof(room));

  room = room_init(1, 10, 10, 10);

  clogf(CAVERNA_LOG_LEVEL_ERROR, "Sizeof(room struct) bytes after = %d", sizeof(room));

	run();

  return 0;
}


