#include "log.h"

#include <stdint.h>

uint8_t current_log_level;

void logging_init(uint8_t log_level) {
  logging_change_log_level(log_level);
}

void logging_change_log_level(uint8_t log_level) {
  current_log_level = log_level;
}

uint8_t logging_get_log_level() {
  return current_log_level;
}

void logging_log_message(uint8_t log_level, char *message) {
  // TODO implement using logging_log_message_format
}

// TODO implement remaining functions

