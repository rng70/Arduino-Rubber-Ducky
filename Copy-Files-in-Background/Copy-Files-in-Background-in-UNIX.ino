/* ---------------------------------------------------------
 * Generated with <3 by Dckuino.js, an open source project !
 *                      *** not tested ***
 * --------------------------------------------------------- */

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void esp_print(String text){
  for (int i = 0; i<=text.length(); i++)
  {
      char val = text[i];
      if (val == ':'){
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.print(".");
        Keyboard.releaseAll();
      }else if (val == '/'){
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.print("7");
        Keyboard.releaseAll();
      }else if (val == '('){
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.print("8");
          Keyboard.releaseAll();
      }else if (val == ')'){
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.print("9");
          Keyboard.releaseAll();
      }else if (val == '='){
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.print("0");
          Keyboard.releaseAll();
      }else if (val == ';'){
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.print(",");
          Keyboard.releaseAll();
      }else if (val == '"'){
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.print("2");
          Keyboard.releaseAll();
      }else if (val == '-'){
          Keyboard.print("/");
      }else if (val == '+'){
          Keyboard.print("]");
      }else if (val == '_'){
          Keyboard.print("?");
      }else if (val == '&'){
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.print("6");
          Keyboard.releaseAll();
      }else if (val == '\\'){
          Keyboard.press(KEY_RIGHT_ALT);
          Keyboard.print("`");
          Keyboard.releaseAll();
      }else{
        Keyboard.print(val);
      }
  }
}

/* Init function */
void setup(){
  // Begining the Keyboard stream
  Keyboard.begin();

  delay(5000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(500);
  Keyboard.releaseAll();

  delay(3000);
  origin_file=""
  destin_file=""
  esp_print("sudo cp "+origin_file+" "+destin_file);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  typeKey(KEY_RETURN);
  delay(2000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.releaseAll();

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
