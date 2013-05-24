#ifndef JNIHELPER_H
#define JNIHELPER_H

#include <jni.h>

namespace gaan
{

/**
 * @brief The JniMethodInfo struct
 */
struct JniMethodInfo
{
    JNIEnv *env;
    jclass classID;
    jmethodID methodID;
};

/**
 * @brief The JniHelper class
 */
class JniHelper
{
public:
    static void setJvm(JavaVM* jvm);

    static JNIEnv *getEnv();

    static bool getStaticMethodInfo(JniMethodInfo *mi, const char *className,
                                    const char *methodName, const char *paramCode);

private:
    static JavaVM* m_jvm;
};

} // namespace gaan

#endif // JNIHELPER_H
