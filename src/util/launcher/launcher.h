/**
 * @brief Functions for bootstrapping the application and launching
 *        the desired execution unit.
 * @author George Peppard
 */
#ifndef CAVERNA_LAUNCHER_H
#define CAVERNA_LAUNCHER_H

/**
 * @brief A CLI argument.
 */
struct cli_argument {
  char *name;
  char *value;
};

/**
 * @brief Launches the application.
 * @param argc  the number of CLI args passed to the application
 * @param argv  the CLI args passed to the application
 */
void launch(int argc, char *argv[]);

#endif // CAVERNA_LAUNCHER_H
