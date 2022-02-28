#include "shader_source.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO: REMOVE THIS IN THE FUTURE, ONLY FOR TESTING
//TODO: REPLACE ALL MALLOC WITH CALLOC
#include <unistd.h>
#include <limits.h>

#include "../../log/log.h"

char* load_shader_source(char *shader_path) {
	FILE *fp;
	// Define the array to read into
	char *full_shader_path;
	char *file_path = (void *)malloc(sizeof(char) * (strlen(__FILE__) + 1));
	strcpy(file_path, __FILE__); // Load the current files path

	// Remove the last 14 characters from the string
	file_path[strlen(file_path) - 15] = '\0';
	// Allocate enough memory to store the file path without the shader_source.c
	char *folder_path = (void *)malloc(sizeof(char) * (strlen(file_path) + 8));

	strcpy(folder_path, file_path);

	// Add sources/ to the path
	strcat(folder_path, "sources/");

	char *content = (void *)calloc(SHADER_SOURCE_MAX_LENGTH, sizeof(char));

	full_shader_path = (void *)malloc(sizeof(char) * (strlen(shader_path)+1+strlen(folder_path))); //+1 for the null character

	// Copy the folder into the new full path variable
	strcpy(full_shader_path, folder_path);

	// Concatenate the shader_path with the folder_path
	strcat(full_shader_path, shader_path);

	printf("Path: %s\n", full_shader_path);

	// Open the file in read mode
	fp = fopen(full_shader_path, "r");

	// Seek to the start of the file
	//fseek(fp, 0, SEEK_SET);

	char *current_line = (void *)calloc(SHADER_SOURCE_MAX_LENGTH, sizeof(char));
	if (fp == NULL) {
		// TODO: Handle file loading error
		clogf(CAVERNA_LOG_LEVEL_FATAL, "Could not load shader from path \"%s\"", full_shader_path);
		char cwd[PATH_MAX];
		getcwd(cwd, sizeof(cwd));
		clogf(CAVERNA_LOG_LEVEL_FATAL, "Current Working Directory: %s", cwd);
	} else {

		while (fgets(current_line, SHADER_SOURCE_MAX_LENGTH, fp) != NULL) {
			//puts(current_line);

			printf("Current line: %s\n", current_line);

			strcat(content, current_line);
		}

		printf("Full Thing: %s\n", content);
		clogf(CAVERNA_LOG_LEVEL_TRACE, "String Length: %i\n", strlen(content));

		//if (fgets(content, SHADER_SOURCE_MAX_LENGTH, fp) != NULL) {
		//	puts(content);
		//} else {
		//	clogf(CAVERNA_LOG_LEVEL_FATAL, "Could not read shader source from path \"%s\"", full_shader_path);
			//TODO: Handle reading error
		//}
	}

	// Close the file
	fclose(fp);

	// Free memory
	free(full_shader_path);
	free(file_path);
	free(folder_path);
	free(current_line);

	return content;

}
