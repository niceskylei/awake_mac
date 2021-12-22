
#import <Foundation/Foundation.h>
#import <IOKit/pwr_mgt/IOPMLib.h>

bool disableScreenSleep(const char *reason, unsigned int *noSleepAssertionID) {
  CFStringRef reasonStr =
      CFStringCreateWithCString(NULL, reason, kCFStringEncodingUTF8);
  int noSleepReturn = IOPMAssertionCreateWithName(
      kIOPMAssertionTypeNoDisplaySleep, kIOPMAssertionLevelOn, reasonStr,
      noSleepAssertionID);
  bool noSleepEnable = noSleepReturn == kIOReturnSuccess;
  return noSleepEnable;
}

bool enableScreenSleep(unsigned int noSleepAssertionID) {
  int noSleepReturn = IOPMAssertionRelease(noSleepAssertionID);
  bool noSleepEnable = noSleepReturn == kIOReturnSuccess;
  return noSleepEnable;
}
