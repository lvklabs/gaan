package com.lvklabs.gaan;

import com.google.analytics.tracking.android.EasyTracker;

public class GAWrapper {
	
	static void sendEvent(String category, String action, String label, long value) {
		EasyTracker.getTracker().sendEvent(category, action, label, value);
	}
}
