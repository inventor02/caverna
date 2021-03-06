################################################################################
# CMakeLists.txt for Caverna                                                   #
# @version 1.1.0                                                               #
# @author George Peppard                                                       #
# @author Toby Godfrey                                                         #
# @author Adam Caine                                                           #
################################################################################

# CMake definitions
cmake_minimum_required(VERSION 3.1)
set(CMAKE_C_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

cmake_policy(SET CMP0072 NEW)

# Project definitions
project(
  Caverna
  VERSION 0.1.0
  DESCRIPTION "A rogue-like game written in OpenGL and C" # TODO change this when we have an actual "description"
  LANGUAGES C)

set(CAVERNA_EXEC_NAME caverna)

# Recursively search for source files
file(GLOB_RECURSE CAVERNA_SOURCE_FILES
  ${CMAKE_SOURCE_DIR}/src/*.c
)

# Packages
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
add_library(GLAD "external/glad/src/glad.c")

set(CAVERNA_LIBS ${CMAKE_DL_LIBS} ${GLFW3_STATIC_LIBRARIES} ${OPENGL_LIBRARIES} GLAD glfw cglm)

# Include DIRs
include_directories(
  "${CMAKE_SOURCE_DIR}/src"
  ${GLFW3_INCLUDE_DIR}
  "${CMAKE_SOURCE_DIR}/external/glad/include"
)

# Executable definitions
add_executable(${CAVERNA_EXEC_NAME} ${CAVERNA_SOURCE_FILES})
target_link_libraries(${CAVERNA_EXEC_NAME} ${CAVERNA_LIBS})

# Inlcude cglm
add_subdirectory(external/cglm/)

# Copy resource folder into build directory
add_custom_command(TARGET ${CAVERNA_EXEC_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${CAVERNA_EXEC_NAME}>/res)

# Compiler and linker options
set(CAVERNA_FLAGS "-lGL -lGLU -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -g -Wall -Werror -pg")
target_compile_options(${CAVERNA_EXEC_NAME} PUBLIC ${CAVERNA_FLAGS})
