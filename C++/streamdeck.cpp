   
#include "Keyboard.h"
// Library with a lot of the HID definitions and methods
// Can be useful to take a look at it see whats available
// https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h

// ----------------------------
// Additional Libraries - each one of these will need to be installed.
// ----------------------------

#include <Keypad.h>
// This library is for interfacing with the 4x4 Matrix
// 
// Can be installed from the library manager, search for "keypad"
// and install the one by Mark Stanley and Alexander Brevig
// https://playground.arduino.cc/Code/Keypad/

#include <LiquidCrystal_I2C.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

// the library will return the character inside this array
// when the appropriate button is pressed.
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
  
};

LiquidCrystal_I2C lcd(0x27,20,4);

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};  //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}



void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    switch (key) {
      case '1':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_LEFT_ARROW);
        break;
      case '2':
        Keyboard.press(KEY_F4);
        break;
      case '3':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_RIGHT_ARROW);
        break;
      case '4':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('c');
        delay(100);
        Keyboard.releaseAll();
        break;
      case '5':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('v');
        delay(100);
        Keyboard.releaseAll();
        break;
      case '6':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('z');
        delay(100);
        break;
      case '7':
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('a');
        Keyboard.releaseAll();
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('d');
        delay(100);
        Keyboard.releaseAll();
        break;
      case '8':
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('v');
        Keyboard.releaseAll();
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('e');
        delay(100);
        Keyboard.releaseAll();
        break;
      case '9':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('c'); 
        delay(1000);
        Keyboard.releaseAll();
        break;
      case '0':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('w'); 
        delay(1000);
        Keyboard.releaseAll();
        break;
      case '*':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('x');
        break;
      case '#':
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_RETURN);
        delay(1000);
        Keyboard.releaseAll();
        break;
      case 'A':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('a');
        break;
      case 'B':
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('s');
        break;
      case 'C':
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('a');
        Keyboard.releaseAll();
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('d');
        Keyboard.releaseAll();
        break;
      case 'D':
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press('d');
        Keyboard.releaseAll();
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('e');
        Keyboard.releaseAll();
    }

    delay(1000);
    Keyboard.releaseAll(); // this releases the buttons
  }
}
