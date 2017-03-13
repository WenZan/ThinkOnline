#include <Wire.h>
#include <dht11.h>
#include "LiquidCrystal_I2C.h"
#define DHT11PIN 3
dht11 DHT11;
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int led = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ;// wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("serial is ok!");
  lcd.init(); 
  lcd.noBacklight();
  lcd.noDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int choice = Serial.read();
    Serial.println(choice, DEC);
    switch (choice) {
      case 5:     //light on
        digitalWrite(led, HIGH);
        break;
      case 1:     //light off
        digitalWrite(led, LOW);
        break;
      case 2:   //music on
        ;
        break;
      case 3:   //music off
        ;
        break;
      case 4:   //tem&shi
        lcd.init();                      // initialize the lcd
        DHT11.read(DHT11PIN);
        lcd.print(" T:");
        lcd.print((int)DHT11.temperature);
        lcd.print("oC   ");
        lcd.print("H:");
        lcd.print((int)DHT11.humidity);
        lcd.print("%");
        lcd.setCursor(6, 1);
        lcd.print("Hi~WenZen!");
        lcd.backlight();
        delay(3000);
        lcd.noBacklight();
        lcd.noDisplay();
        break;
    }
  }
}
