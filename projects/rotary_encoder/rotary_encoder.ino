/* Read Quadrature Encoder
  * Connect Encoder to Pins encoder0PinA, encoder0PinB, and +5V.
  *
  * Sketch by max wolf / www.meso.net
  * v. 0.1 - very basic functions - mw 20061220
  *
  */  
/* add servo motion now */

#include <Servo.h> 

Servo myservo;

 int val; 
 int encoder0PinA = 3;
 int encoder0PinB = 4;
 int encoder0Pos = 0;
 int encoder0PinALast = LOW;
 int n = LOW;
 int count = 0;
 int servoPos = 0;
 
 void setup() { 
   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
   Serial.begin (9600);
 } 

 void loop() { 
   n = digitalRead(encoder0PinA);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     count++;
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
       servoPos += 5;
       if (servoPos > 179)
         servoPos = 0;
     } else {
       encoder0Pos++;
       servoPos -= 5;
       if (servoPos < 0)
         servoPos = 179;
     }
     Serial.println (encoder0Pos);
     myservo.write(servoPos); 
     delay(15);
   } 
   encoder0PinALast = n;
 } 
