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
	run();

  return 0;
}


