#include "gaan/EasyTracker.h"
#include "gaan/JniHelper.h"

extern "C"
{

jint JNI_OnLoad(JavaVM *jvm, void */*reserved*/)
{
    gaan::JniHelper::setJvm(jvm);

    return JNI_VERSION_1_4;
}

void Java_com_example_googleanalyticsandroidndk_MainActivity_testAnalytics(JNIEnv* /*env*/, jobject /*thiz*/)
{
    // send events example:
    gaan::EasyTracker::sendEvent("TestCategory", "TestAction1", "TestLabel1", 123);
    gaan::EasyTracker::sendEvent("TestCategory", "TestAction1", "TestLabel2", 456);
    gaan::EasyTracker::sendEvent("TestCategory", "TestAction2", "TestLabel1", 789);
}

} // extern "C"

