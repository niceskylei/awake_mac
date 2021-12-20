#include <IOKit/pwr_mgt/IOPMLib.h>

bool disableScreenSleep(const char *reason, IOPMAssertionID *noSleepAssertionID);
bool enableScreenSleep(IOPMAssertionID noSleepAssertionID);