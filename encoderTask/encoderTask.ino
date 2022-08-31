#include <Event.h>//tiimer lib
#include <Timer.h>
int motor1PWM = 9;//motor1 PWM speed cotrol
int motor1dirc = 7;//motor1 direction control the other direction control on Motor driver will be XOR with this signal
int motor2PWM = 10;//motor2 PWM speed cotrol
int motor2dirc = 8;//motor2 direction control the other direction control on Motor driver will be XOR with this signal
int P_A1 = 2;// A pin from the first arm encoder
int P_B1 = 3;//B pin
int P_A2 = 4;//A pin from second arm encoder 
int P_B2 = 5;//B pin
int sw = 6;// the Switch
long long count1=0;// counter for the first encoder
long long count2=0;// counter for the second encoder
float angle1,angle2,diff1,diff2;//vars
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
  attachInterrupt(P_A1,ISRA1,CHANGE);//interrupt for A1
  attachInterrupt(P_B1,ISRB1,CHANGE);//             B1
  attachInterrupt(P_A2,ISRA2,CHANGE);//             A2
  attachInterrupt(P_B2,ISRB2,CHANGE);//             B2
  mytime.every(10,updateAngle);//updating the angle every 10 millie second
}
void loop() {
  if(digitalRead(sw)==0){//if the swith is 0 go to the First position
    sw_0();
    sw_02();
  }
   else{//else Second Position
    sw_0();
    sw_12();
   }
}
void updateAngle(){
  angle1=(count1*360)/2400;//calculate the Boh angles from encoders Counters
  angle2=(count2*360)/2400;
  Serial.print("angle1 = ");//printing the angles
  Serial.print(angle1);
  Serial.print("angle2 = ");
  Serial.print(angle2);
}
void sw_0(){//here we used Porpotional control Method for all arms positions cuz it's easier and i was in harry
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
void ISRA1(){//ISR for A pin from encoder NO.1
  if(digitalRead(P_A1) !=digitalRead(P_B1))
    count1++;
   else
    count1--;
}
void ISRB1(){//ISR for B pin from encoder NO.1
  if(digitalRead(P_A1) ==digitalRead(P_B1))
    count1++;
   else
    count1--;
}
void ISRA2(){//ISR for A pin from encoder NO.2
  if(digitalRead(P_A2) !=digitalRead(P_B2))
    count2++;
   else
    count2--;
}
void ISRB2(){//ISR for B pin from encoder NO.2
  if(digitalRead(P_A2) ==digitalRead(P_B2))
    count2++;
   else
    count2--;
}
