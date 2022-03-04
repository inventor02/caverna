#ifndef CAVERNA_RENDERMASTER
#define CAVERNA_RENDERMASTER

#include <cglm/cglm.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils/log/log.h"
#include "utils/log/proginfo.h"

int run();


extern unsigned int cav_vao, cav_vbo, cav_ebo, cav_vertex, cav_frag, cav_shader_program;

#endif
