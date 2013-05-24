/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Copyright (c) 2013 Andres Pagliano

http://www.lvklabs.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

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
