# Introduction
This is a concept of floating mod menu without overlay permission. This menu will help you get around some basic anti-cheat. It will only work if the menu has been called from Activity, not Application context. Otherwise you would get an error `java.lang.ClassCastException: ____ cannot be cast to android.app.Activity`

Sorry to disappoint you, but this is not a full menu project, just like a demo project and I have not implemented a fallback yet. You could try implement yourself, and make it ask for overlay permission and run service, if it fails. Don't cry if I don't want to spoonfeed

Thanks to DarkSide for his idea and sent me his project, but I have improved the project quite a bit

# How to add menu

For those who knew how to add menu to the game, it's the same way as the regular LGL menu, but without adding overlay permission and services

Decompile APK, both game and menu app

Copy menu smali file to the game. Doesn't matter what classes folder you are copying on

Find main activity from `AndroidManifest.xml` and open the main smali file

Now, this is important. Pay attention to the class name on the first line. Is it an activity? or is it an application?

We can easly determite that this is an activity

![](https://i.imgur.com/iXQD6H6.png)

But what about this? It's an application context. Menu will not work with it

![](https://i.imgur.com/APZytXN.png)

But if you are unsure, just give it a try. Otherwise, find another smali that has `OnCreate` method

And add menu call below `OnCreate` method:

`invoke-static {p0}, Lcom/mod/Main;->Start(Landroid/content/Context;)V`

![](https://i.imgur.com/F1Xsynx.png)

Compile

That is simple

If you didn't know my mod menu project, please check this out: https://github.com/LGLTeam/Android-Mod-Menu/wiki

# Preview

![](https://i.imgur.com/avoNVXU.gif)
