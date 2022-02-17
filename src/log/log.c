#include "log.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint8_t current_log_level;

char *get_log_color(uint8_t log_level) {
  switch (log_level) {
    case CAVERNA_LOG_LEVEL_FATAL: return ANSI_COLOR_FATAL;
    case CAVERNA_LOG_LEVEL_ERROR: return ANSI_COLOR_ERROR;
    case CAVERNA_LOG_LEVEL_WARNING: return ANSI_COLOR_WARNING;
    case CAVERNA_LOG_LEVEL_INFO: return ANSI_COLOR_INFO;
    case CAVERNA_LOG_LEVEL_DEBUG: return ANSI_COLOR_DEBUG;
    case CAVERNA_LOG_LEVEL_TRACE: return ANSI_COLOR_TRACE;
    default: return ANSI_COLOR_RESET;
  }
}

char *get_log_level_name(uint8_t log_level) {
  switch (log_level) {
    case CAVERNA_LOG_LEVEL_FATAL: return "FATAL";
    case CAVERNA_LOG_LEVEL_ERROR: return "ERROR";
    case CAVERNA_LOG_LEVEL_WARNING: return "WARNING";
    case CAVERNA_LOG_LEVEL_INFO: return "INFO";
    case CAVERNA_LOG_LEVEL_DEBUG: return "DEBUG";
    case CAVERNA_LOG_LEVEL_TRACE: return "TRACE";
    default: return "INFO";
  }
}

char *get_short_file_name(const char *file_name) {
  char *last_slash = strrchr(file_name, '/');
  return (last_slash + 1);
}

void logging_init(uint8_t log_level) {
  logging_change_log_level(log_level);
  clogf(CAVERNA_LOG_LEVEL_INFO, "Log level is %s", get_log_level_name(current_log_level));
}

void logging_change_log_level(uint8_t log_level) {
  current_log_level = log_level;
}

uint8_t logging_get_log_level() {
  return current_log_level;
}

void logging_log_message(const char *file, const char *func, int line, uint8_t log_level, char *message) {
  logging_log_message_format(file, func, line, log_level, "%s", message);
}

void logging_log_message_format(const char *file, const char *func, int line, uint8_t log_level, char *format, ...) {
  if (log_level > current_log_level) {
    return;
  }

  char *color = get_log_color(log_level);
  char *message = calloc(128 + strlen(format), sizeof(char));

  sprintf(message, "%s[%-7s] [%-12s %-12s L%-3d] ", get_log_color(log_level), get_log_level_name(log_level), get_short_file_name(file), func, line);

  va_list argp;
  va_start(argp, format);
  vsprintf(message + strlen(message), format, argp);
  va_end(argp);

  sprintf(message + strlen(message), "%s", ANSI_COLOR_RESET);
  printf("%s\n", message);

  free(message);
  message = NULL;
}

void logging_destroy() {
  return;
}

