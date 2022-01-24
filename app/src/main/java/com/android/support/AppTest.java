package com.android.support;

import android.app.Application;
import android.content.Context;

/* loaded from: classes.dex */
public class AppTest extends Application {
    private static AppTest instance;

    public AppTest() {
        instance = this;
    }

    public static AppTest getInstance() {
        return instance;
    }

    /* JADX INFO: Access modifiers changed from: protected */
    @Override // android.content.ContextWrapper
    public void attachBaseContext(Context context) {
        super.attachBaseContext(context);
    }

    @Override // android.app.Application
    public void onCreate() {
        //Used to test to launch menu with application context

        Main.Start(this);

        super.onCreate();
    }
}