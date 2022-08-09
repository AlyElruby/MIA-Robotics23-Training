#include <Wire.h>
unsigned int upperByte, lowerByte,moist, moistpercent=0;
int temp;
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293
void setup(){
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
Wire.begin();
Serial.begin(9600);
}
void loop(){
delay(10);
Wire.requestFrom(8,1);// requesting the data form the slave address 8
temp = Wire.read();//reading the sent data 
digitalWrite(4,HIGH);//it is optional just for synchonrization
if (Serial.available()>0)//to check if there's a sent data
{
     upperByte = Serial.read();//reading the upper byte
     lowerByte = Serial.read();//reading the lower byte
  digitalWrite(4,LOW);//to complete synchonrization
moist= (upperByte << 8) + lowerByte ;//to return back the orignal value if the moisture value
moistpercent=map(moist,0,873,0,100);// turning it into percentage to be easier to plot and understand Note that i found in that sensor the max is 873 not 1023 as it supposed to be
Serial.println(temp);// plot the temp
Serial.print(" ");
Serial.println(moistpercent);//plot the moist pecentage
 delay(50);
}
  if(temp>40){// the code to controll the motor according to temp it's easy to be read to i will not comment this part
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
  }
  else if(temp<20){
   digitalWrite(motorPin3, LOW);
   digitalWrite(motorPin4, HIGH);
  }
  else{
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
}
