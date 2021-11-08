/* ----------------------- */
/*    tested by rng70      */
/* ----------------------- */


#include "Keyboard.h"

void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}


void activarnarrador(){
  delay(500);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('u');
  Keyboard.releaseAll();
  delay(2500);

  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(500);

  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  Keyboard.write(' ');
  delay(500);

  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  Keyboard.write(' ');
  delay(500);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();
}


void setup(){
  // Begining the Keyboard stream
  Keyboard.begin();
  delay(1000);
  activarnarrador();
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
