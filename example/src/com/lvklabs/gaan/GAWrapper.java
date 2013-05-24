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
