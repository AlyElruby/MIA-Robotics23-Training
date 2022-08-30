#include <Event.h>
#include <Timer.h>
int motor1dirc1 = 9;
int motor1dirc2 = 10;
int motor2dirc1 = 11;
int motor2dirc2 = 12;
#define PA1  2
#define PB1  3 
#define PA2  4
#define PB2  5
#define sw   6
long long count1=0;
long long count2=0;
float angle1,angle2;
Timer mytime;//creating an object from class timer
void setup() {
  Serial.begin(9600);//to use the serial monitor
  pinMode(motor1dirc1,INPUT);
  pinMode(motor1dirc2,INPUT);
  pinMode(motor2dirc1,INPUT);
  pinMode(motor2dirc2,INPUT);
  pinMode(PA1,INPUT_PULLUP);
  pinMode(PB1,INPUT_PULLUP);
  pinMode(PA2,INPUT_PULLUP);
  pinMode(PB2,INPUT_PULLUP);
  pinMode(sw,INPUT);//pull down this button on circuit
  attachInterrupt(PA1,ISRA1,CHANGE);
  attachInterrupt(PB1,ISRB1,CHANGE);
  attachInterrupt(PA2,ISRA2,CHANGE);
  attachInterrupt(PB2,ISRB2,CHANGE);
  mytime.every(10,updateAngle);
}
void loop() {
  if(digitalRead(sw)==0){
    sw0();
    sw02();
  }
   else{
    sw0();
    sw12();
   }
}
void updateAngle(){
  angle1=(count1*360)/2400;
  angle2=(count2*360)/2400;
}
void sw0(){
  if(angle1<60){
    digitalWrite(motor1dirc1,HIGH);
    digitalWrite(motor1dirc2,LOW);
  }
  else if(angle1>60){
    digitalWrite(motor1dirc1,LOW);
    digitalWrite(motor1dirc2,HIGH);
  }
  else{
    digitalWrite(motor1dirc1,HIGH);
    digitalWrite(motor1dirc2,HIGH);
  }
}
void sw02(){
  if(angle2<0){
    digitalWrite(motor2dirc1,HIGH);
    digitalWrite(motor2dirc2,LOW);
  }
  else if(angle2>0){
    digitalWrite(motor2dirc1,LOW);
    digitalWrite(motor2dirc2,HIGH);
  }
  else{
    digitalWrite(motor2dirc1,HIGH);
    digitalWrite(motor2dirc2,HIGH);
  }
}
void sw12(){
  if(angle1<90){
    digitalWrite(motor2dirc1,HIGH);
    digitalWrite(motor2dirc2,LOW);
  }
  else if(angle1>90){
    digitalWrite(motor2dirc1,LOW);
    digitalWrite(motor2dirc2,HIGH);
  }
  else{
    digitalWrite(motor2dirc1,HIGH);
    digitalWrite(motor2dirc2,HIGH);
  }
}
void ISRA1(){
  if(digitalRead(PA1) !=digitalRead(PB1))
    count1++;
   else
    count1--;
}
void ISRB1(){
  if(digitalRead(PA1) ==digitalRead(PB1))
    count1++;
   else
    count1--;
}
void ISRA2(){
  if(digitalRead(PA2) !=digitalRead(PB2))
    count2++;
   else
    count2--;
}
void ISRB2(){
  if(digitalRead(PA2) ==digitalRead(PB2))
    count2++;
   else
    count2--;
}
