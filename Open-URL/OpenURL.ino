#include <Mouse.h>
#include <Keyboard.h>

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
  delay(3000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  Keyboard.releaseAll();

  delay(500);

  // Change the URL to any other link
  Keyboard.print("https://github.com/rng70");

  delay(500);

  typeKey(KEY_RETURN);

  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
  Mouse.end();
}

// Unused
void loop() {}
