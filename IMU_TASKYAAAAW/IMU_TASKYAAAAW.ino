#include <Event.h>
#include <Timer.h>
#include<Wire.h>
const int MPU=0x68;  // I2C address of the MPU6050
int16_t GyZ=0;
double elapsedTime=0, currentTime=0, previousTime=0,yaaaaaw=0;
Timer mytime;//creating an object from timer lib
void setup()
{
  Serial.begin(9600);//begin serial monitor
  Wire.begin();//begin I2C
  MPU_init();//calling function to start configration of MPU device
  MPU_GyroConfig();//calling function to start configration of GYRO sensor
  mytime.every(10,angleMeasure);//calc the angle every 10 mille second
}
void loop()
{
  //NO NEED TO BE USED
}
void angleMeasure(){//function to calc the yaaaaaaw angle
  Wire.beginTransmission(MPU);
  Wire.write(0x47);  // starting with register 0x47 GYRO_ZOUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,2,true);// request 2 registers
  GyZ=Wire.read()<<8|Wire.read();// 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L) concatination
  Wire.endTransmission();//end trans
  previousTime = currentTime;// PreviousTime store the previous CurrentTime
  currentTime = millis();// CurrentTime is read
  elapsedTime = (currentTime - previousTime)/1000; //the elapsedTime in seconds
  yaaaaaw =  yaaaaaw + GyZ * elapsedTime;//gettin yaw by the simple EQN s=s+v*t supposing that it's moving in const speed or by supposeing it will measure the angle every instance as integration
  Serial.print("YAAAAAAW =");//printing yaaaaaw E4TA NSOOR
  Serial.println(yaaaaaw);
}
void MPU_init(){//function to start configration of MPU device
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // PWR_MGMT_1 REG addres
  Wire.write(0x00);     // set to zero (wakes up the MPU6050)
  Wire.endTransmission();// end trans
}
void MPU_GyroConfig(){//function to start configration of GYRO sensor
  Wire.beginTransmission(MPU);
  Wire.write(0x1B);  // GYROSCPE config register addres
  Wire.write(0x18);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission();//end trans
}
