#include "render_master.h"

#include <cglm/cglm.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "util/log/log.h"
#include "util/log/proginfo.h"
#include "util/files/resource_loader.h"

unsigned int cav_vao, cav_vbo, cav_ebo, cav_frag, cav_vertex, cav_shader_program;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processEvent(GLFWwindow *window);

void vboBufferDataExample(float *vertices, int size_of_arr, const char *vertex_src, const char *frag_src);

void render();

void printSize(float *vertices) {
	clogf(CAVERNA_LOG_LEVEL_TRACE, "Number of elements the array can hold: %i", sizeof(vertices)/sizeof(float));
}

int run() {

	//////////////// Garbage example data delete later ////////////////////////
	float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

	for (int i = 0; i < 9; i++) {
		clogf(CAVERNA_LOG_LEVEL_TRACE, "Element %i : Value %f\n", i, vertices[i]);
	}

	char *vertexShaderSource = load_shader_source("example.vert");
	char *fragmentShaderSource = load_shader_source("example.frag");

	printf("VERT pointer: %i, FRAG pointer: %i\n", vertexShaderSource, fragmentShaderSource);


	clogf(CAVERNA_LOG_LEVEL_TRACE, "Number of elements the array can hold: %i", sizeof(vertices)/sizeof(float));

	printSize(vertices);




	////////////////////////////////////////////////////////////////////////////

	// INIT FUNCTION
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Window!", NULL, NULL);
	if (window == NULL) {
		clog(CAVERNA_LOG_LEVEL_FATAL, "Failed to create GLFW window!\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		clog(CAVERNA_LOG_LEVEL_FATAL, "Failed to initialize GLAD!\n");
		return -1;
	}

	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// END OF INIT FUNCTION

	// Simple code to test cglm functionality //
	//
	mat4 m = GLM_MAT4_IDENTITY_INIT;

	glm_mat4_mul(m, m, m);
	////////////////////////////////////////////

	// NEED TO SPLIT THIS UP
	vboBufferDataExample(vertices, 9, vertexShaderSource, fragmentShaderSource);

	// CREATE THIS LOOP IN ANOTHER FUNCTION
	while(!glfwWindowShouldClose(window)) {

		processEvent(window);



		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// NEEDS TO BE EXTERNAL
		render();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// DESTROY FUNCTION

	// NEED TO DEALLOCATE VUFFERS AND RESOURCES HERE

	glfwTerminate();

	return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// CHANGE TO DIFFERENT FILE -> EVENT_MASTER?
void processEvent(GLFWwindow *window) {
	// Code to process window
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, 1);
	}
}

void vboBufferDataExample(float *vertices, int size_of_arr,const char *vertex_src, const char *frag_src) {

	clog(CAVERNA_LOG_LEVEL_TRACE, vertex_src);
	clog(CAVERNA_LOG_LEVEL_TRACE, frag_src);

	// BUFFER MASTER STUFF
	// GEN FUNCTIONS
	glGenVertexArrays(1, &cav_vao);
	glGenBuffers(1, &cav_vbo);

	// BIND FUNCTIONS
	glBindVertexArray(cav_vao);

	// Generate Vertex Buffer Object

	glBindBuffer(GL_ARRAY_BUFFER, cav_vbo);

	clogf(CAVERNA_LOG_LEVEL_TRACE, "size of vertices: %i\n", sizeof(vertices)/sizeof(float));

	// BUFFER DATA FUNCTIONS
	// Send the data away
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size_of_arr, vertices, GL_STATIC_DRAW);

	// Set vertex attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// SHADER MASTER STUFF
	// CREATE SHADER FUNCTION
	// Generate a basic shader
	cav_vertex = glCreateShader(GL_VERTEX_SHADER);
	cav_frag = glCreateShader(GL_FRAGMENT_SHADER);

	// Attach source code to shader
	glShaderSource(cav_vertex, 1, &vertex_src, NULL);
	glShaderSource(cav_frag, 1, &frag_src, NULL);

	char info_log[512];
	int success;
	glCompileShader(cav_vertex);

	// Check for compile errors
	glGetShaderiv(cav_vertex, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(cav_vertex, 512, NULL, info_log);
		clog(CAVERNA_LOG_LEVEL_ERROR, info_log);
	}

	glCompileShader(cav_frag);

	glGetShaderiv(cav_frag, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(cav_frag, 512, NULL, info_log);
		clog(CAVERNA_LOG_LEVEL_ERROR, info_log);
	}

	// Shader Program Stuff
	cav_shader_program = glCreateProgram();
	glAttachShader(cav_shader_program, cav_vertex);
	glAttachShader(cav_shader_program, cav_frag);
	glLinkProgram(cav_shader_program);

	// Check for linking errors
	glGetProgramiv(cav_shader_program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(cav_shader_program, 512, NULL, info_log);
		clog(CAVERNA_LOG_LEVEL_ERROR, info_log);
	}

	// USE SHADER FUNCTION
	// Use the shader
	glUseProgram(cav_shader_program);

	// Delete Shaders Once Linked
	// PART OF CREATE SHADER FUNCTION
	glDeleteShader(cav_vertex);
	glDeleteShader(cav_frag);
}

void render() {
	// SPLIT UP INTO DIFFERENT FILES
	glUseProgram(cav_shader_program);
	glBindVertexArray(cav_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
