/*********************

  Example code for the Adafruit RGB Character LCD Shield and Library.
  Modified to use with SunFouner RFB LCD Shield

  This code displays text on the shield, and also reads the buttons on the keypad.
  When a button is pressed, the backlight changes color.

**********************/
// include the library code:
#include <Wire.h>
#include <SunFounder_RGBLCDShield.h>

// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
SunFounder_RGBLCDShield lcd = SunFounder_RGBLCDShield();

void setup() {
  // Debugging output
  Serial.begin(9600);
  lcd.begin(16, 2);

  // Print a message to the LCD. We track how long it takes since
  // this library has been optimized a bit and we're proud of it :)
  int time = millis();
  lcd.print("Hello, world!");
  time = millis() - time;
  Serial.print("Took "); Serial.print(time); Serial.println(" ms");
  lcd.setBacklight(1);

}

uint8_t i = 0;
uint8_t colour = 0;

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);

  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    lcd.clear();
    lcd.setCursor(0, 0);
    if (buttons & BUTTON_UP) {
      lcd.print("UP ");
    }
    if (buttons & BUTTON_DOWN) {
      lcd.print("DOWN ");
    }
    if (buttons & BUTTON_LEFT) {
      lcd.print("LEFT ");
    }
    if (buttons & BUTTON_RIGHT) {
      lcd.print("RIGHT ");
    }
    if (buttons & BUTTON_SELECT) {
      // select button change RGB Led colour.
      lcd.print("SELECT ");
      lcd.setRGBLedColour(colour);
      colour ++;
      if (colour > 7) {
        colour = 0;
      }
    }
  }
}
