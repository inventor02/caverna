#include "resource_loader.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WINDOWS) || defined(_WIN32) || defined(_WIN64)
	// If a windows machine, use the direct library to get the cwd method
	#include <direct.h>
	#define GetCurrentDirectory _getcwd
#else
	// If on a UNIX based machine, use the unistd library to get the cwd method
	#include <unistd.h>
	#define GetCurrentDirectory getcwd
#endif

#include "util/log/log.h"

//TODO: REPLACE ALL MALLOC WITH CALLOC

char* load_shader_source(char *shader_path) {
  // Create a file pointer
	FILE *fp;
	// Define the array to read into
	char *full_shader_path;

  /////// FIGURE OUT THE ABSOLUTE PATH OF THE /res/shader/ FOLDER/////////

  char cwd[PATH_MAX];
  GetCurrentDirectory(cwd, sizeof(cwd));

  //TODO: CHECK IF getcwd fails

  // Append /res/shader to the path
	// First allocate enough memory for the full path
	full_shader_path = (void *)malloc(sizeof(char) * (strlen(cwd) + strlen(shader_path) + 1 + 12));

	// TODO: Free up memory
	// Copy the cwd into the full path
	strcpy(full_shader_path, cwd);

	// Concatenate '/res/shader/' onto the full path
	strcat(full_shader_path, "/res/shader/");

	// And finally the relative path ontop
	strcat(full_shader_path, shader_path);

	char *content = (void *)calloc(SHADER_SOURCE_MAX_LENGTH, sizeof(char));

	printf("Path: %s\n", full_shader_path);

	// Open the file in read mode
	fp = fopen(full_shader_path, "r");

	// Seek to the start of the file
	//fseek(fp, 0, SEEK_SET);

	char *current_line = (void *)calloc(SHADER_SOURCE_MAX_LENGTH, sizeof(char));
	if (fp == NULL) {
		// TODO: Handle file loading error
		clogf(CAVERNA_LOG_LEVEL_FATAL, "Could not load shader from path \"%s\"", full_shader_path);
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
	free(current_line);

	return content;

}

