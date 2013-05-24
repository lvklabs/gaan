## GoogleAnalyticsAndroidNdk

Android NDK wrapper for the Google Analytics API V2

_Why?_

This wrapper is intended for Android NDK apps that needs to invoke the Google Analytics API. 
More notably are games written in C++ / Cocos2d-x as is my case ;)

### Status

I've just started this project. Currently, only supports:

 - [Event tracking](https://developers.google.com/analytics/devguides/collection/android/v2/events)
 - [Screen tracking](https://developers.google.com/analytics/devguides/collection/android/v2/screens)


### Instructions

I asumme that you are familiar with Google Analytics API and Android NDK. If not, please read first:

 - https://developers.google.com/analytics/devguides/collection/android/v2/ (1)
 - http://developer.android.com/tools/sdk/ndk/index.html
 
Your project must integrate the Google Analytics SDK as explained in (1). 

Then add the JNI wrapper as follows:

1. Copy `<thisrepo>/src` to `<yourproject>/src` and update your project to compile those new source files
2. Copy `<thisrepo>/jni/gaan` to `<yourproject>/jni`
3. Edit or create `<yourproject>/jni/Application.mk` and add:

```
APP_STL += gnustl_static
```

4. Edit `<yourproject>/jni/Android.mk` and add __two__ lines:

```
LOCAL_WHOLE_STATIC_LIBRARIES += gaan 
include $(BUILD_SHARED_LIBRARY)      # this line *already* exists in your file
$(call import-module, gaan)          
```

(Yes, the order is important!)


### Example

The `example/` directory contains an Eclipse project with a fully working example.

__NOTE:__ To compile it needs the ndk-build command to be in your `PATH` enviroment variable.

