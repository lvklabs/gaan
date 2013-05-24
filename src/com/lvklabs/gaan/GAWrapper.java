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

package com.lvklabs.gaan;

import com.google.analytics.tracking.android.EasyTracker;

/**
 * The GAWrapper is a thin wrapper to ease the invocation from C++
 */
public class GAWrapper {
	
	static void sendEvent(String category, String action, String label, long value) {
		EasyTracker.getTracker().sendEvent(category, action, label, value);
	}
	
	static void sendView(String appScreen) {
		EasyTracker.getTracker().sendView(appScreen);
	}
}
