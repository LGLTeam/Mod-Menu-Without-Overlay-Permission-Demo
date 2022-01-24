package com.android.support;

import android.app.*;
import android.os.*;

public class ActivityMain extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        Main.Start(this);
    }
}
