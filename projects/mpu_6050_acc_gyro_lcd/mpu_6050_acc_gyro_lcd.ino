// MPU-6050 Short Example Sketch
// By Arduino User JohnChi
// August 17, 2014
// Public Domain
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.clear();
  lcd.print ("start in 2 sec");
  delay(2000);
  lcd.clear();

}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  char stringBuffer[20];

  sprintf (stringBuffer,"AX:%6d", AcX);
  lcd.setCursor(0,0);
  lcd.print (stringBuffer);
  sprintf (stringBuffer,"AY:%6d", AcY);
  lcd.setCursor(0,1);
  lcd.print (stringBuffer);
  sprintf (stringBuffer,"AZ:%6d", AcZ);
  lcd.setCursor(0,2);
  lcd.print (stringBuffer);
  sprintf (stringBuffer,"GX:%6d", GyX);
  lcd.setCursor(10,0);
  lcd.print (stringBuffer);
  sprintf (stringBuffer,"GY:%6d", GyY);
  lcd.setCursor(10,1);
  lcd.print (stringBuffer);
  sprintf (stringBuffer,"GZ:%6d", GyZ);
  lcd.setCursor(10,2);
  lcd.print (stringBuffer);

  delay(333);
}
