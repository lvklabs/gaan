#include "JniHelper.h"

#if DEBUG_JNI_HELPER
#  include <android/log.h>
#  define  LOGDEBUG(...)  __android_log_print(ANDROID_LOG_DEBUG, "gaan::JniHelper", __VA_ARGS__)
#else
#  define  LOGDEBUG(...)
#endif

namespace gaan
{

JavaVM * JniHelper::m_jvm = 0;

void JniHelper::setJvm(JavaVM *jvm)
{
    m_jvm = jvm;
}

JNIEnv *JniHelper::getEnv()
{
    if (!m_jvm) {
        LOGDEBUG("No JVM found");
        return 0;
    }

    JNIEnv *env = 0;

    if (m_jvm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK) {
        LOGDEBUG("Unable to get the environment");
        return 0;
    }

    if (m_jvm->AttachCurrentThread(&env, 0) < 0) {
        LOGDEBUG("Unable to attach current thread");
        return 0;
    }

    return env;
}

bool JniHelper::getStaticMethodInfo(JniMethodInfo *mi, const char *className,
                                    const char *methodName, const char *paramCode)
{
    JNIEnv * env = getEnv();

    if (!env) {
        return false;
    }

    jclass classID = env->FindClass(className);

    if (!classID) {
        LOGDEBUG("Class not found: %s", className);
        return false;
    }

    jmethodID methodID = env->GetStaticMethodID(classID, methodName, paramCode);

    if (!methodID) {
        LOGDEBUG("Static method not found: %s", methodName);
        return false;
    }

    mi->env = env;
    mi->classID = classID;
    mi->methodID = methodID;

    return true;
}

} // namespace gaan
