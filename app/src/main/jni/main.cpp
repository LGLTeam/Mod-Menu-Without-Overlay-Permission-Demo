#include <pthread.h>
#include <jni.h>
#include <Includes/Utils.h>
#include <Substrate/SubstrateHook.h>
#include "KittyMemory/MemoryPatch.h"
#include <Icon.h>
#include <Includes/Chams.h>
extern "C" {
	bool wall, Dropk, Air = false;
	 
    struct My_Patches {MemoryPatch Bypass, wall, Dropk, Air;} hexPatches;
    const char *libName = "libil2cpp.so";
	
    JNIEXPORT jstring JNICALL
    Java_com_mod_Main_apk(
        JNIEnv *env,
        jclass activityObject) {
    jstring str = env->NewStringUTF("    Modded by Darkside");// do not earse the space this for normal text view
    return str;
}
    JNIEXPORT jstring JNICALL
    Java_com_mod_Main_down(
        JNIEnv *env,
        jclass activityObject) {
    jstring str = env->NewStringUTF("Telegram:@DarkSide | YouTube:Darkside");
        return str;
    }
    
JNIEXPORT jobjectArray JNICALL
Java_com_mod_Main_getFeatures(
        JNIEnv *env,
        jclass activityObject) {
    jobjectArray ret;
    const char *features[] = {          
		    "Text_Text︎",//0
            "ButtonOnOff_ButtonOnOff",//1
            "Button_Button",//2
            "SeekBar_SeekBar_0_100",//3
			"Text_Settings",
            "Hide_Icon invisible",
            };

    int Total_Feature = (sizeof features /
                         sizeof features[0]); //Now you dont have to manually update the number everytime;

    ret = (jobjectArray) env->NewObjectArray(Total_Feature, env->FindClass("java/lang/String"),
                                             env->NewStringUTF(""));
    int i;
    for (i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));
    return (ret);
} 
JNIEXPORT void JNICALL
Java_com_mod_Main_Changes(
        JNIEnv *env,
        jclass activityObject,
        jint feature,
        jint value) {
    switch (feature) {
        case 0:
        break;				
	}
}
JNIEXPORT jstring JNICALL
Java_com_mod_menu_Menu_SliderString(
        JNIEnv *env,
        jobject clazz, jint feature, jint value) {
    // You must count your features from 0, not 1
    const char *SliderStr;
    if (feature == 555) {
        switch (value) {
            case 0:
                SliderStr = "Default";
                break;
            case 1:
                SliderStr = "2x";
                break;
            case 2:
                SliderStr = "4x";
                break;
            case 3:
                SliderStr = "8x";
                break;
            case 4:
                SliderStr = "12x";
                break;
            case 5:
                SliderStr = "24x";
                break;
        }
        return env->NewStringUTF(SliderStr);
    }
    if (feature == 500) {
        switch (value) {
            case 0:
                SliderStr = "Neck";
                break;
            case 1:
                SliderStr = "Hip";
                break;
            case 2:
                SliderStr = "Head";
                break;
        }
        return env->NewStringUTF(SliderStr);
    }
    if (feature == 500) {
        if (value <= 15){
            SliderStr = "Low";
        }
        else if (value >= 15 && value <= 35){
            SliderStr = "Medium";
        }
        else if (value >= 35){
            SliderStr = "High";
        }
        return env->NewStringUTF(SliderStr);
    }
    return env->NewStringUTF(NULL);
}
}
// ---------- Hooking ---------- //


void *hack_thread(void *) {
    
    /*ProcMap il2cppMap;
    do {
        il2cppMap = KittyMemory::getLibraryMap(libName);
        sleep(1);
    } while (!il2cppMap.isValid() && mlovinit());*/
    //setShader("_BumpMap");
    //LogShaders();
    //Wallhack();
   
   return NULL;
}

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *globalEnv;
    vm->GetEnv((void **) &globalEnv, JNI_VERSION_1_6);

    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL
JNI_OnUnload(JavaVM *vm, void *reserved) {}

