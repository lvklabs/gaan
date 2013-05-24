LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := gaan
LOCAL_SRC_FILES := EasyTracker.cpp JniHelper.cpp

include $(BUILD_STATIC_LIBRARY)
