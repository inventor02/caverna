#include "proginfo.h"

#include "log.h"

void preamble() {
  clogf(CAVERNA_LOG_LEVEL_INFO, "Welcome to CAVERNA %s", "0.1.0");
  disp_short_license();
  clog(CAVERNA_LOG_LEVEL_INFO, "--------------------------------------------------------------------------------------------------------");
}

void disp_short_license() {
  clog(CAVERNA_LOG_LEVEL_INFO, "Caverna   Copyright (C) 2022 George Peppard, Toby Godfrey, Adam Caine and Eleanor Heywood");
  clog(CAVERNA_LOG_LEVEL_INFO, "This program comes with ABSOLUTELY NO WARRANTY; for details run with the --license flag.");
  clog(CAVERNA_LOG_LEVEL_INFO, "This is free software, and you are welcome to redistribute it");
  clog(CAVERNA_LOG_LEVEL_INFO, "under certain conditions; see the GNU General Public License 3.0 for details.");
}

void long_license() {
  clog(CAVERNA_LOG_LEVEL_ERROR, "Not yet implemented");
  // TODO implement this
}
