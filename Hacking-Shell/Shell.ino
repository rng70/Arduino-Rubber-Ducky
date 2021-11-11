/* -----------------------
 *     tested by rng70
 * for changing cmd color
 * ----------------------- */

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

  // Pick color
  Keyboard.print("color a");
  delay(100);
  typeKey(KEY_RETURN);

  // Set window title
  Keyboard.print("title HACKING SHELL");
  delay(100);
  typeKey(KEY_RETURN);
  delay(100);

  // Disable echoing
  Keyboard.print("@echo off");
  typeKey(KEY_RETURN);
  delay(100);

  // Launch tree
  Keyboard.print("tree");
  delay(100);
  typeKey(KEY_RETURN);

  // End Payload
}

// Unused
void loop() {}
