// WARNING!
// NOT TESTED
/* -----------------------------------------------------------------------------------------
 * GET A BUTTON IF YOU WANT TO USE THIS CODE
 * WITHOUT STOPPING CODE EXECUTION YOU WON'T BE ABLE TO PROPERLY USE YOUR ARDUINO EVER AGAIN
 * BECAUSE LOOP IS ALWAYS RUNNING
 * ------------------------------------------------------------------------------------------ */

#include <HID.h>
#include <Keyboard.h>

// Init function
// Utility function
void typeKey(int key){
  Keyboard.press(key);
  delay(500);
  Keyboard.release(key);
}

void setup() {
  // Button Code to Disable executing
  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW){
  while(1);
}}

// Start Loop
void loop() {
  Keyboard.begin();
  Keyboard.press(KEY_LEFT_CTRL);
  delay(500);
  Keyboard.press('w');
}
