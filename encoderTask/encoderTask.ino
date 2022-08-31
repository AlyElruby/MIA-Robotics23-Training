#include <Event.h>
#include <Timer.h>
int motor1PWM = 9;
int motor1dirc = 7;
int motor2PWM = 10;
int motor2dirc = 8;
int P_A1 = 2;
int P_B1 = 3;
int P_A2 = 4;
int P_B2 = 5;
int sw = 6;
long long count1=0;
long long count2=0;
float angle1,angle2,diff1,diff2;
Timer mytime;//creating an object from class timer
void setup() {
  Serial.begin(9600);//to use the serial monitor
  pinMode(motor1dirc,OUTPUT);
  pinMode(motor2dirc,OUTPUT);
  pinMode(motor1PWM,OUTPUT);
  pinMode(motor2PWM,OUTPUT);
  pinMode(P_A1,INPUT_PULLUP);
  pinMode(P_B1,INPUT_PULLUP);
  pinMode(P_A2,INPUT_PULLUP);
  pinMode(P_B2,INPUT_PULLUP);
  pinMode(sw,INPUT);//pull down this button on circuit
  attachInterrupt(P_A1,ISRA1,CHANGE);
  attachInterrupt(P_B1,ISRB1,CHANGE);
  attachInterrupt(P_A2,ISRA2,CHANGE);
  attachInterrupt(P_B2,ISRB2,CHANGE);
  mytime.every(10,updateAngle);
}
void loop() {
  if(digitalRead(sw)==0){
    sw_0();
    sw_02();
  }
   else{
    sw_0();
    sw_12();
   }
}
void updateAngle(){
  angle1=(count1*360)/2400;
  angle2=(count2*360)/2400;
  Serial.print("angle1 = ");
  Serial.print(angle1);
  Serial.print("angle2 = ");
  Serial.print(angle2);
}
void sw_0(){
  diff1=60-angle1;
  digitalWrite(motor1dirc,LOW);
  analogWrite(motor1PWM,map(diff1,0,60,0,255));
}
void sw_02(){
  diff2=angle2-0;
  digitalWrite(motor2dirc,HIGH);
  analogWrite(motor2PWM,map(diff2,0,90,0,255));
}
void sw_12(){
  diff2=90-angle2;
  digitalWrite(motor2dirc,LOW);
  analogWrite(motor2PWM,map(diff2,0,90,0,255));
}
void ISRA1(){
  if(digitalRead(P_A1) !=digitalRead(P_B1))
    count1++;
   else
    count1--;
}
void ISRB1(){
  if(digitalRead(P_A1) ==digitalRead(P_B1))
    count1++;
   else
    count1--;
}
void ISRA2(){
  if(digitalRead(P_A2) !=digitalRead(P_B2))
    count2++;
   else
    count2--;
}
void ISRB2(){
  if(digitalRead(P_A2) ==digitalRead(P_B2))
    count2++;
   else
    count2--;
}
