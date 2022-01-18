package com.mod;

import android.app.Activity;
import android.content.*;
import android.graphics.*;
import android.net.Uri;
import android.os.*;
import android.provider.Settings;
import android.view.*;
import android.text.*;
import android.widget.*;

import com.mod.menu.Menu;

public class Main {
    protected static Context context;
    protected LinearLayout childOfScroll;

    public static native void Changes(int feature, int value);

    private static native String[] getFeatures();

    public static boolean hide;

    private static native String icon();

    public static native String apk();

    private static native String down();

    public static void Start(final Context context) {
        System.loadLibrary("MyLibName");
        Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                new Main().MenuMain(context);
            }
        }, 500);
    }

    public final void MenuMain(final Context context) {
        if (context instanceof Activity) {
            Main.context = context;
            Menu menu = new Menu(context);
            menu.setWidth(menu.dpi(310));
            menu.setHeight(menu.dpi(250));
            menu.setIconImage(icon());
            menu.setTitle(apk());

            menu.setBackground(Color.RED);
            TextView BB = new TextView(context);
            BB.setText(Html.fromHtml(down()));
            BB.setTextColor(Color.WHITE);
            BB.setTextSize(13.5f);
            BB.setGravity(Gravity.CENTER);
            menu.getChildOfScroll().addView(BB);
            String[] listFT = getFeatures();
            for (int i = 0; i < listFT.length; i++) {
                final int feature = i;
                String str = listFT[i];
                String[] split = str.split("_");
                if (str.contains("ButtonOnOff_")) {
                    menu.ButtonOnOff(feature, split[1], new Menu.ibt() {
                        public void OnWrite() {
                            Changes(feature, 0);
                        }
                    });
                } else if (str.contains("Button_")) {
                    menu.Button(feature, split[1], new Menu.ibt() {
                        public void OnWrite() {
                            Changes(feature, 0);
                        }
                    });
                } else if (str.contains("Hide_")) {
                    menu.Button(feature, split[1], new Menu.ibt() {
                        public void OnWrite() {
                            hide = !hide;
                        }
                    });
                } else if (str.contains("Text_")) {
                    menu.addText(str.replace("Text_", ""));
                } else if (str.contains("SeekBar_")) {

                    menu.SeekBar(feature, split[1], Integer.parseInt(split[2]), Integer.parseInt(split[3]), new Menu.iit() {
                        public void OnWrite(int i) {
                            Changes(feature, i);
                        }
                    });
                }
            }
        } else {
            Toast.makeText(context.getApplicationContext(), "Could not launch menu. Make sure the main class of the game is an Activity, not an Application context", Toast.LENGTH_LONG).show();
            Toast.makeText(context.getApplicationContext(), "Could not launch menu. Make sure the main class of the game is an Activity, not an Application context", Toast.LENGTH_LONG).show();
        }
    }
}

