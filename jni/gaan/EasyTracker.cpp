/****************************************************************************
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

#include "EasyTracker.h"
#include "JniHelper.h"

#define WRAPPER_CLASS            "com/lvklabs/gaan/GAWrapper"
#define SEND_EVENT_METHOD        "sendEvent"
#define SEND_EVENT_PARAMS        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;J)V"
#define SEND_VIEW_METHOD         "sendView"
#define SEND_VIEW_PARAMS         "(Ljava/lang/String;)V"

namespace gaan
{

void EasyTracker::sendEvent(const std::string &category,
                            const std::string &action,
                            const std::string &label,
                            long value)
{
    JniMethodInfo mi;

    if (JniHelper::getStaticMethodInfo(&mi, WRAPPER_CLASS, SEND_EVENT_METHOD, SEND_EVENT_PARAMS)) {
        jstring jCategory = mi.env->NewStringUTF(category.c_str());
        jstring jAction = mi.env->NewStringUTF(action.c_str());
        jstring jLabel = mi.env->NewStringUTF(label.c_str());
        jlong   jValue = value;

        mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, jCategory, jAction, jLabel, jValue);

        mi.env->DeleteLocalRef(jCategory);
        mi.env->DeleteLocalRef(jAction);
        mi.env->DeleteLocalRef(jLabel);
        mi.env->DeleteLocalRef(mi.classID);
    }
}

void EasyTracker::sendView(const std::string &appScreen)
{
    JniMethodInfo mi;

    if (JniHelper::getStaticMethodInfo(&mi, WRAPPER_CLASS, SEND_VIEW_METHOD, SEND_VIEW_PARAMS)) {
        jstring jAppScreen = mi.env->NewStringUTF(appScreen.c_str());

        mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, jAppScreen);

        mi.env->DeleteLocalRef(jAppScreen);
        mi.env->DeleteLocalRef(mi.classID);
    }
}

} // namespace gaan




