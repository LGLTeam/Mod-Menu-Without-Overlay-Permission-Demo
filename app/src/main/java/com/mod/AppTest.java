package com.mod;

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
        //Main.Start(this);

        super.onCreate();
    }
}