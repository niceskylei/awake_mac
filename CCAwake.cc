#include <stdio.h>

bool disableScreenSleep(const char *reason, unsigned int *noSleepAssertionID) {
  printf("disableScreenSleep in CCAwake.cc\n");
  return false;
}

bool enableScreenSleep(unsigned int noSleepAssertionID) {
  printf("enableScreenSleep in CCAwake.cc\n");
  return false;
}
