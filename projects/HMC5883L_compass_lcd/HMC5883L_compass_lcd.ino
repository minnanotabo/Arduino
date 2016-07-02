#include <Wire.h> //I2C Arduino Library
#include <LiquidCrystal_I2C.h>

#define address 0x1E //0011110b, I2C 7bit address of HMC5883

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


void setup(){
  //Initialize Serial and I2C communications
  //Serial.begin(9600);
  Wire.begin();
  
  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(address); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.clear();
  lcd.print ("start in 2 sec");
  delay(2000);
  lcd.clear();

}

void loop(){
  
  int x,y,z; //triple axis data

  //Tell the HMC5883L where to begin reading data
  Wire.beginTransmission(address);
  Wire.write(0x03); //select register 3, X MSB register
  Wire.endTransmission();
  
 
 //Read data from each axis, 2 registers per axis
  Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    x = Wire.read()<<8; //X msb
    x |= Wire.read(); //X lsb
    z = Wire.read()<<8; //Z msb
    z |= Wire.read(); //Z lsb
    y = Wire.read()<<8; //Y msb
    y |= Wire.read(); //Y lsb
  }
  
  //Print out values of each axis

  char stringBuffer[20];

  sprintf (stringBuffer,"x: %5d", x);
  lcd.setCursor(0,0);
  lcd.print (stringBuffer);
  sprintf (stringBuffer,"y: %5d", y);
  lcd.setCursor(0,1);
  lcd.print (stringBuffer);
  sprintf (stringBuffer,"z: %5d", z);
  lcd.setCursor(0,2);
  lcd.print (stringBuffer);

  delay(250);
}

