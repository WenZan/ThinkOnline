#include <Wire.h> 
#include <dht11.h>
#include "LiquidCrystal_I2C.h"

#define DHT11PIN 3
dht11 DHT11;

int lightOr=2;   //define set backlight input pin
int light;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  pinMode(lightOr,INPUT);
}

void loop()
{
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
  light=digitalRead(lightOr); 
  if(light==HIGH){
    lcd.backlight();
    delay(3000);
  }
  lcd.noBacklight();
}
