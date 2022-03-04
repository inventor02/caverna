/**
 * @brief Resourceloading functions.
 *
 * Contains functions to load various resources
 * from the resource folder.
 *
 * @author Adam Caine
 */
#ifndef RESOURCE_LOADER_H
#define RESOURCE_LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/log/log.h"

#define SHADER_SOURCE_MAX_LENGTH 1024

/**
 * @brief Loads the shader source found at the path provided.
 *
 * The shader path provided should be relative to the sources
 * folder found inside of the shader folder of the resource directory.
 * Please note that the character array returned by this function
 * must be freed once it has been used.
 *
 * @param shader_path the relative path to the shader
 *
 * @returns the shader source code
 */
char* load_shader_source(char *shader_path);


#endif //RESOURCE_LOADER_H

