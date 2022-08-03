
#import <Foundation/Foundation.h>
#import <AppKit/NSWorkspace.h>
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


bool openUrl(const char *urlChar) {
  // CFStringRef urlStr = CFStringCreateWithCString(NULL, urlChar, kCFStringEncodingUTF8);
  NSString* urlStr = [NSString stringWithUTF8String:urlChar];
  NSURL* url = [[NSURL alloc]initWithString:urlStr];
  bool isOk = [[NSWorkspace sharedWorkspace] openURL:url];
  return isOk;
}
