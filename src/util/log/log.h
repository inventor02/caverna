/**
 * @brief A collection of logging helper functions.
 *
 * Contains logging helper functions which handle setting the log level,
 * determining which messages to log, and adding appropriate information
 * to each log line to aid with debugging.
 *
 * @author George Peppard
 */
#ifndef CAVERNA_LOG_H
#define CAVERNA_LOG_H

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#define clog(log_level, message) logging_log_message(__FILE__, __func__, __LINE__, log_level, message)
#define clogf(log_level, format, ...) logging_log_message_format(__FILE__, __func__, __LINE__, log_level, format, __VA_ARGS__)

// The greater the log level, the more verbose the messages.
#define CAVERNA_LOG_LEVEL_FATAL     0
#define CAVERNA_LOG_LEVEL_ERROR     1
#define CAVERNA_LOG_LEVEL_WARNING   2
#define CAVERNA_LOG_LEVEL_INFO      3
#define CAVERNA_LOG_LEVEL_DEBUG     4
#define CAVERNA_LOG_LEVEL_TRACE     5

#define ANSI_COLOR_FATAL            "\033[38;5;160m"
#define ANSI_COLOR_ERROR            "\033[38;5;197m"
#define ANSI_COLOR_WARNING          "\033[38;5;214m"
#define ANSI_COLOR_INFO             "\033[38;5;75m"
#define ANSI_COLOR_DEBUG            "\033[38;5;250m"
#define ANSI_COLOR_TRACE            "\033[38;5;245m"
#define ANSI_COLOR_RESET            "\033[0m"

// TODO implement defines to include the source application unit and file etc

/**
 * @brief Initialises logging for the application.
 * @param log_level the log level to initialise logging with
 */
void logging_init(uint8_t log_level);

/**
 * @brief Changes the log level currently in use.
 * @param log_level the log level to change to
 */
void logging_change_log_level(uint8_t log_level);

/**
 * @brief Gets the log level currently in use.
 * @returns the log level currently in use
 */
uint8_t logging_get_log_level();

/***
 * @brief Logs a simple message to the console.
 *
 * If more advanced formatting needs are required, use logging_log_message_format()
 * instead.
 *
 * @param source      the source of the log message
 * @param log_level   the log level to log the message with
 * @param message     the message to log
 */
void logging_log_message(const char *file, const char *func, int line, uint8_t log_level, char *message);

/**
 * @brief Formats and logs a message to the console.
 *
 * For more simple logging needs, use logging_log_message() instead.
 *
 * For documentation on formatting strings, see the POSIX Programmers
 * Manual for the printf function.
 *
 * @param source      the source of the log message
 * @param log_level   the log level to log the message with
 * @param format      the string to format and then log
 * @param ...         the elements to insert into the format string
 */
void logging_log_message_format(const char *file, const char *func, int line, uint8_t log_level, char *format, ...);

/**
 * @brief Tears down logging information in memory before application exit.
 *
 * As there is no current need for this to exist, it does not do anything, but
 * should be implemented anyway in case of future changes to this unit.
 */
void logging_quit();

#endif // CAVERNA_LOG_H
