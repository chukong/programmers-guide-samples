LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../src/AppDelegate.cpp \
                   ../../src/MainScene.cpp \
									 ../../src/chapter2/Chapter2.cpp \
									 ../../src/chapter2/Chapter2Level1.cpp \
									 ../../src/chapter3/Chapter3.cpp \
									 ../../src/chapter4/Chapter4.cpp \
									 ../../src/chapter5/Chapter5.cpp \
									 ../../src/chapter6/Chapter6.cpp \
									 ../../src/chapter6/Chapter6_1.cpp \
									 ../../src/chapter6/Chapter6_2.cpp \
									 ../../src/chapter6/Chapter6_3.cpp \
									 ../../src/chapter6/Chapter6_4.cpp \
									 ../../src/chapter6/Chapter6_5.cpp \
									 ../../src/chapter6/Chapter6_6.cpp \
									 ../../src/chapter6/Chapter6_7.cpp \
									 ../../src/chapter7/Chapter7.cpp \
									 ../../src/chapter7/Chapter7_1.cpp \
									 ../../src/chapter7/Chapter7_2.cpp \
									 ../../src/chapter7/Chapter7_3.cpp \
									 ../../src/chapter9/Chapter9.cpp \
									 ../../src/chapter9/Chapter9_1.cpp \
									 ../../src/chapter9/Chapter9_2.cpp \
									 ../../src/chapter9/Chapter9_3.cpp \
									 ../../src/chapter9/Chapter9_4.cpp \
									 ../../src/chapter9/Chapter9_5.cpp \
									 ../../src/chapter9/Chapter9_6.cpp \
									 ../../src/chapter9/Chapter9_7.cpp \
									 ../../src/chapter9/Chapter9_8.cpp \
									 ../../src/chapter9/Chapter9_9.cpp \
									 ../../src/chapter9/Chapter9_10.cpp \
									 ../../src/chapter9/DrawNode3D.cpp \
									 ../../src/chapter12/Chapter12.cpp \
									 ../../src/chapter13/Chapter13.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../src \
$(LOCAL_PATH)/../../src/chapter2 \
$(LOCAL_PATH)/../../src/chapter3 \
$(LOCAL_PATH)/../../src/chapter4 \
$(LOCAL_PATH)/../../src/chapter5 \
$(LOCAL_PATH)/../../src/chapter6 \
$(LOCAL_PATH)/../../src/chapter7 \
$(LOCAL_PATH)/../../src/chapter9 \
$(LOCAL_PATH)/../../src/chapter12 \
$(LOCAL_PATH)/../../src/chapter13 

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,./prebuilt-mk)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
