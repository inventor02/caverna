#include "render_master.h"

#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

#include "log/log.h"
#include "log/proginfo.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processEvent(GLFWwindow *window);

void vboBufferDataExample(float *vertices, const char *vertex_src, const char *frag_src);

void render();

int run() {

	//////////////// Garbage example data delete later ////////////////////////
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	const char *vertexShaderSource = "#version 330 core\nlayout (location = 0) in vec3 aPos;\nvoid main()\n{\n  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n}\0";
	const char *fragmentShaderSource = "#version 330 core\nout vec4 FragColor;\nvoid main()\n{\n  FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n}\0";




	////////////////////////////////////////////////////////////////////////////

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

	// Simple code to test cglm functionality
	//
	mat4 m = GLM_MAT4_IDENTITY_INIT;

	glm_mat4_mul(m, m, m);

	vboBufferDataExample(vertices, vertexShaderSource, fragmentShaderSource);

	while(!glfwWindowShouldClose(window)) {

		processEvent(window);

		glfwSwapBuffers(window);
		glfwPollEvents();


		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		render();
	}

	glfwTerminate();

	return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processEvent(GLFWwindow *window) {
	// Code to process window
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, 1);
	}
}

void vboBufferDataExample(float *vertices, const char *vertex_src, const char *frag_src) {

	glGenVertexArrays(1, &cav_vao);

	// Generate Vertex Buffer Object
	glGenBuffers(1, &cav_vbo);

	glBindBuffer(GL_ARRAY_BUFFER, cav_vbo);

	// Send the data away
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Set vertex attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Generate a basic shader
	cav_vertex = glCreateShader(GL_VERTEX_SHADER);
	cav_frag = glCreateShader(GL_FRAGMENT_SHADER);

	// Attach source code to shader
	glShaderSource(cav_vertex, 1, &vertex_src, NULL);
	glShaderSource(cav_frag, 1, &frag_src, NULL);
	glCompileShader(cav_vertex);
	glCompileShader(cav_frag);

	// Shader Program Stuff
	cav_shader_program = glCreateProgram();
	glAttachShader(cav_shader_program, cav_vertex);
	glAttachShader(cav_shader_program, cav_frag);
	glLinkProgram(cav_shader_program);

	// Use the shader
	glUseProgram(cav_shader_program);

	// Delete Shaders Once Linked
	glDeleteShader(cav_vertex);
	glDeleteShader(cav_frag);
}

void render() {
	glUseProgram(cav_shader_program);
	glBindVertexArray(cav_vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
