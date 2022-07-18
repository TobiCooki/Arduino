#include <DigiKeyboard.h>


void setup() {
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("microsoftedge.exe"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print(F("https://www.famousbirthdays.com/people/mrpancake4343.html"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
}

void loop() {
  DigiKeyboard.write('\t');
  DigiKeyboard.write('\t');
  DigiKeyboard.write('\t');
  DigiKeyboard.write('\t');
  DigiKeyboard.write('\t');
  DigiKeyboard.write('\t');
  DigiKeyboard.write('\t');
  DigiKeyboard.write('\t');
  DigiKeyboard.write('\t');
  DigiKeyboard.write('\t');
  DigiKeyboard.write('\t');
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.write('\t');
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_CONTROL_LEFT);
  DigiKeyboard.delay(3000);
}
