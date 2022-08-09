#include <Wire.h>//adding i2c lib
int tempsens=A0;//temperuture sensor
int temp;
int reading;//this will be used if the temp sensor is lm35
float ref =5.0;/and this too
float reselution=1023.0;/and this
void setup() {
Serial.begin(9600);
Wire.begin(8);//the slave address
Wire.onRequest(requestEvent);//requesting to send data
pinMode(tempsens,INPUT);
}
void loop() {
reading =analogRead(tempsens);//read the sensor
temp=map(((reading - 20) * 3.04), 0, 1023, -40, 125);//having the right reading in celecus
temp=constrain(temp, 0, 100);//to make sure that it will not be out 100 and 0
}
void requestEvent(){
Wire.write(temp);
}
