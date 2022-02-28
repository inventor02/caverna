/**
 * @brief Shader source loading functions.
 *
 * Contains functions to load the source code of various
 * shader types.
 *
 * @author Adam Caine
 */
#ifndef SHADER_SOURCE_H
#define SHADER_SOURCE_H

#define SHADER_SOURCE_MAX_LENGTH 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../log/log.h"

/**
 * @brief Loads the shader source found at the path provided.
 *
 * The shader path provided should be relative to the sources
 * folder found inside of the shader folder of the src directory.
 * Please note that the character array returned by this function
 * must be freed once it has been used.
 *
 * @param shader_path the relative path to the shader
 *
 * @returns the shader source code
 */
char* load_shader_source(char *shader_path);


#endif //SHADER_SOURCE_H
