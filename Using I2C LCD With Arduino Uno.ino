#include <LiquidCrystal_I2C.h>

// Initialize the library with the I2C address of the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD
  lcd.init();

  // Turn on the backlight
  lcd.backlight();

  // Clear the LCD screen
  lcd.clear();

  // Print a message to the LCD
  lcd.setCursor(0, 0); // Set the cursor to the first row
  lcd.print("Hello, world!"); // Print the message
}

void loop() {
  // Do nothing in the loop
}

