

/*
 Demonstration sketch for Adafruit i2c/SPI LCD backpack
 using MCP23008 I2C expander
 ( http://www.ladyada.net/products/i2cspilcdbackpack/index.html )

 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * 5V to Arduino 5V pin
 * GND to Arduino GND pin
 * CLK to Analog #5
 * DAT to Analog #4
*/

// include the library code:
#include <Wire.h>
#include <LiquidTWI.h>

// Connect via i2c, default address #0 (A0-A2 not jumpered)
LiquidTWI lcd(0);
unsigned long time  = 0;

void setup()
{
 Serial.begin(9600);  
 Serial.print("Intentando communicar por I2C"); 
 
  // set up the LCD's number of rows and columns: 
 lcd.begin(16, 2);
 
 if (lcd.NoComm)
 {
    Serial.print("No se ha podido comunicar");
    lcd.NoComm  = false;
 }
}

void loop() 
{
  if (millis()-time>=500)
  {
     time = millis();
     lcd.begin(16, 2);
 
     if (lcd.NoComm)
     {
        Serial.print("No se ha podido comunicar");
        lcd.NoComm  = false;
     }
  }
  
  
}

