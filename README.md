# BuiltIOBackend SDK for iOS

The BuiltIO Backend helps you to create iOS apps quickly and effortlessly, taking care of all the backend requirements. For more information see the [website](https://docs.built.io/) and [getting started](https://docs.built.io/guide#gettingstarted).

#### Installation Options
##### Manual

1. Download the [Latest iOS SDK release](https://github.com/raweng/BuiltIOBackend-iOS/releases) and extract the zip file to your local disk.

2. Drag and drop BuiltIO.framework into your project folder in Xcode.

    A window will appear, prompting you to choose one of the options for adding files. Click the ‘Destination’ checkbox to copy items into the destination group’s folder. This will add  the SDK to your project.

3. In the project editor, select your app under `TARGETS`. Under the `General` tab, open `Linked Frameworks and Libraries` and add the following libraries:
    - Accounts.framework
    - CFNetwork.framework
    - CoreGraphics.framework
    - CoreLocation.framework
    - CoreTelephony.framework
    - MobileCoreServices.framework
    - Security.framework
    - Social.framework
    - SystemConfiguration.framework
    - libicucore.dylib
    - libsqlite3.dylib

4. In your target app, click on the `Build Settings` tab and add the `-ObjC` flag to `Other Linker Flags`.

##### **[CocoaPods](https://cocoapods.org)**

Add the following line to your Podfile in your desired target:
```sh
target '<iOSTargetName>' do
platform :ios, '7.0'
pod 'BuiltIOBackend'
end

target '<WatchAppTarget>' do
platform :ios, '7.0'
pod 'BuiltIOBackend'
end```

Run `pod install`, and you should now have the latest BuiltIOBackend release.

#### Import Header/Module
You can import header file in Objective-C project as:
```sh
 #import <BuiltIO/BuiltIO.h>
```
You can also import as a Module:

```sh
//Objc
@import BuiltIO

//Swift
import BuiltIO
```
#### Other Links
- [QuickStart](https://docs.built.io/quickstart)
- [Developer Guide](https://docs.built.io/guide)
- [API Docs](http://iossdk.builtapp.io/) 

## License

```
Copyright (c) 2012-present, Built.io.
All rights reserved.
```
