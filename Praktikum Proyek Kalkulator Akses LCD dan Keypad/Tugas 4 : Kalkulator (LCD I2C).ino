#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0x27);

double total = 0;

// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

char operation = '\0'; // Inisialisasi karakter operasi

const byte Rows = 4; // Four rows
const byte COLS = 4; // Three columns

// Define the Keymap
char keys[Rows][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'=', '0', '/', '.'}
};

byte rowPins[Rows] = {0, 1, 2, 3}; // Connect keypad ROW0, ROW1, ROW2, ROW3

Keypad keypad = Keypad(makeKeymap(keys), rowPins);
