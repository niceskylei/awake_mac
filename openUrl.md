```
# macOS 10.15 System Preference Panes

Below are a list of System Preference pane URLs and paths that can be accessed with scripting to assist users with enabling macOS security settings without having to walk them through launching System Preferences, finding panes, and scrolling to settings. Not all panes have an accessible anchor and some are OS specific.

To find the Pane ID of a specific pane, open the System Preferences app and select the desired Preference Pane. With the pane selected, open the ScriptEditor.app and run the following script to copy the current Pane ID to your clipboard and display any available anchors:

```bash
tell application "System Preferences"
	set CurrentPane to the id of the current pane
	set the clipboard to CurrentPane
	get the name of every anchor of current pane
end tell
```

### Opening with URL Schemes

If the preference pane supports it, you can open them with a URL in terminal using the following syntax (replace `<PaneID>` with the desired pane ID):

```bash
open "x-apple.systempreferences:<PaneID>"
```

### Open with System Preferences Bundle Identifier and Pane Path

You can also access the main preference panes using the file path to each pane from `/System/Library/PreferencePanes/` using the `open` command with slightly different syntax (replace `/Path/To/Pane` with your desired pane):

```bash
open -b com.apple.systempreferences /Path/To/Pane
```

# Preference Panes

Below are all the panes that display on most Macs running 10.15 Catalina but there are a few that are ommitted that are available on later versions of Apple hardware or installed plugins. If the pane supports being opened with  URL then it is listed, otherwise you can use the path.

### Apple ID Pane

`/System/Library/PreferencePanes/AppleIDPrefPane.prefPane`

### Family Sharing Pane

`/System/Library/PreferencePanes/FamilySharingPrefPane.prefPane`

### General Pane

`/System/Library/PreferencePanes/Appearance.prefPane`

### Desktop & Screen Saver Pane

`/System/Library/PreferencePanes/DesktopScreenEffectsPref.prefPane`

### Dock Pane

`/System/Library/PreferencePanes/Dock.prefPane`

### Mission Control Pane

`/System/Library/PreferencePanes/Expose.prefPane`

### Siri Pane

```
com.apple.preference.speech
/System/Library/PreferencePanes/Speech.prefPane
```

### Spotlight Pane

`/System/Library/PreferencePanes/Spotlight.prefPane`

### Language & Region Pane

`/System/Library/PreferencePanes/Localization.prefPane`

### Notifications Pane

```bash
com.apple.preference.notifications
open -b com.apple.systempreferences /System/Library/PreferencePanes/Notifications.prefPane
```

### Internet Accounts Pane

`/System/Library/PreferencePanes/InternetAccounts.prefPane`

### Users & Groups Pane

`/System/Library/PreferencePanes/Accounts.prefPane`

### Accessibility Pane

```bash
com.apple.preference.universalaccess
/System/Library/PreferencePanes/UniversalAccessPref.prefPane
```

- __Display__
  `com.apple.preference.universalaccess?Seeing_Display`
- __Zoom__
  `com.apple.preference.universalaccess?Seeing_Zoom`
- __VoiceOver__
  `com.apple.preference.universalaccess?Seeing_VoiceOver`
- __Descriptions__
  `com.apple.preference.universalaccess?Media_Descriptions`
- __Captions__
  `com.apple.preference.universalaccess?Captioning`
- __Audio__
  `com.apple.preference.universalaccess?Hearing`
- __Keyboard__
  `com.apple.preference.universalaccess?Keyboard`
- __Mouse & Trackpad__
  `com.apple.preference.universalaccess?Mouse`
- __Switch Control__
  `com.apple.preference.universalaccess?Switch`
- __Dictation__
  `com.apple.preference.universalaccess?SpeakableItems`

### Screen Time

```bash
com.apple.preference.screentime
/System/Library/PreferencePanes/ScreenTime.prefPane
```

### Extensions Pane

`/System/Library/PreferencePanes/Extensions.prefPane`

### Security & Privacy Pane

*Tip: The "Advanced" anchor will initially open S&P pane to your last used tab (General, FileValut, Firewall, Privacy)but if the pane is already open it triggers a the panel unlock wherever the user may be at in the Security and Privacy pane. So, if you want them to enable a specific Privacy setting, open the desired Privacy anchor first (e.g. ?Privacy_Contacts) and then open the Advanced anchor (?Advanced) to prompt the user password to unlock the preference pane.*

#### Main Tabs

```
com.apple.preference.security
/System/Library/PreferencePanes/Security.prefPane
```

- __General__
  `com.apple.preference.security?General`
- __Advanced__
  `com.apple.preference.security?Advanced`
- __FileVault__
  `com.apple.preference.security?FDE`
- __Firewall__
  `com.apple.preference.security?Firewall`
- __Privacy Main__
  `com.apple.preference.security?Privacy`

#### Privacy Anchors

- __Location Services__
  `com.apple.preference.security?Privacy_LocationServices`
- __Contacts__
  `com.apple.preference.security?Privacy_Contacts`
- __Calendars__
  `com.apple.preference.security?Privacy_Calendars`
- __Reminders__
  `com.apple.preference.security?Privacy_Reminders`
- __Photos__
  `com.apple.preference.security?Privacy_Photos`
- __Camera__
  `com.apple.preference.security?Privacy_Camera`
- __Microphone__
  `com.apple.preference.security?Privacy_Microphone`
- __Speech Recognition__
  `com.apple.preference.security?Privacy_SpeechRecognition`
- __Accessibility__
  `com.apple.preference.security?Privacy_Accessibility`
- __Input Monitoring__ Not Available
- __Full Disk Access__
  `com.apple.preference.security?Privacy_AllFiles`
- __Files and Folders__ Not Available
- __Screen Recording__ Not Available
- __Automation__
  `com.apple.preference.security?Privacy_Automation`
- __Analytics and Improvements__
  `com.apple.preference.security?Privacy_Diagnostics`
- __Advertising__
  `com.apple.preference.security?Privacy_Advertising`

### Software Update Pane

`/System/Library/PreferencePanes/SoftwareUpdate.prefPane`

### Network Pane

`/System/Library/PreferencePanes/Network.prefPane`

### Bluetooth Pane

`/System/Library/PreferencePanes/Bluetooth.prefPane`

### Sound Pane

`/System/Library/PreferencePanes/Sound.prefPane`

### Printers & Scanners Pane

```bash
/System/Library/PreferencePanes/PrintAndFax.prefPane
/System/Library/PreferencePanes/PrintAndScan.prefPane
```

### Keyboard Pane

`/System/Library/PreferencePanes/Keyboard.prefPane`

- __Dictation__
  `com.apple.preference.speech?Dictation`

### Trackpad Pane

`/System/Library/PreferencePanes/Trackpad.prefPane`

### Mouse Pane

`/System/Library/PreferencePanes/Mouse.prefPane`

### Displays Pane

`/System/Library/PreferencePanes/Displays.prefPane`

### Energy Saver Pane

`/System/Library/PreferencePanes/EnergySaver.prefPane`

### Date & Time Pane

`/System/Library/PreferencePanes/DateAndTime.prefPane`

### Sharing Preference Pane

```bash
com.apple.preferences.sharing
/System/Library/PreferencePanes/SharingPref.prefPane
```

- __Screen Sharing__
  `com.apple.preferences.sharing?Services_ScreenSharing`
- __File Sharing__
  `com.apple.preferences.sharing?Services_PersonalFileSharing`
- __Printer Sharing__
  `com.apple.preferences.sharing?Services_PrinterSharing`
- __Remote Login__
  `com.apple.preferences.sharing?Services_RemoteLogin`
- __Remote Management__
  `com.apple.preferences.sharing?Services_ARDService`
- __Remote Apple Events__
  `com.apple.preferences.sharing?Services_RemoteAppleEvent`
- __Internet Sharing__
  `com.apple.preferences.sharing?Internet`
- __Bluetooth Sharing__
  `com.apple.preferences.sharing?Services_BluetoothSharing`

### Time Machine Pane

`/System/Library/PreferencePanes/TimeMachine.prefPane`

### Startup Disk Pane

`/System/Library/PreferencePanes/StartupDisk.prefPane`

### Profiles Pane

`/System/Library/PreferencePanes/Profiles.prefPane`

```

```
