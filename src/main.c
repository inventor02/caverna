#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cglm/cglm.h>

#include "log/log.h"
#include "log/proginfo.h"
#include "render/render_master.h"
#include "terrain_generation/terrain_generation.h"


int main() {
  logging_init(5);
  preamble();

	run();

  struct room thisRoom = room_init(1);
  generate_level(&thisRoom);

	return 0;
}


