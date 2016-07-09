/* Read Quadrature Encoder
  * Connect Encoder to Pins encoder0PinA, encoder0PinB, and +5V.
  *
  * Sketch by max wolf / www.meso.net
  * v. 0.1 - very basic functions - mw 20061220
  *
  */  


/* add LCD display */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display

 int val; 
 int encoder0PinA = 3;
 int encoder0PinB = 4;
 int encoder0Pos = 0;
 int encoder0PinALast = LOW;
 int n = LOW;
 int count = 0;
 
 void setup() { 
   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);
   lcd.init();                      // initialize the lcd 
   lcd.backlight();
   lcd.clear();
   lcd.print ("start in 2 sec");
   delay(2000);
   lcd.clear();
 } 

 void loop() { 
   
   char stringBuffer[20];
   n = digitalRead(encoder0PinA);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     count++;
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
     } else {
       encoder0Pos++;
     }
     sprintf (stringBuffer,"rot:%5d", encoder0Pos);
     lcd.setCursor(0,0);
     lcd.print (stringBuffer);
     delay(15);
   } 
   encoder0PinALast = n;
 } 
