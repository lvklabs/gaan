LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := example
LOCAL_SRC_FILES := main.cpp

############### ADD THIS TO YOUR PROJECT ##################
LOCAL_WHOLE_STATIC_LIBRARIES += gaan
###########################################################

include $(BUILD_SHARED_LIBRARY)

############### ADD THIS TO YOUR PROJECT ##################
$(call import-module, gaan)
###########################################################

