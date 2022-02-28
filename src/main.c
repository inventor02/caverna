#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cglm/cglm.h>

#include "util/log/log.h"
#include "util/log/proginfo.h"
#include "render/render_master.h"


int main() {
  logging_init(5);
  preamble();



	run();

  return 0;
}


