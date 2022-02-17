/**
 * @brief Contains functions for outputting program information.
 * @author George Peppard
 */
#ifndef CAVERNA_PROGINFO_H
#define CAVERNA_PROGINFO_H

#include "log.h"

/**
 * @brief Displays the preamble including version and short license info.
 */
void preamble();

/**
 * @brief Displays the short license info.
 */
void disp_short_license();

/**
 * @brief Displays longer license information on request.
 */
void long_license();

#endif // CAVERNA_PROGINFO_H
