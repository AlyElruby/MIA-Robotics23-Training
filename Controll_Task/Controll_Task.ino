#include <Event.h>
#include <Timer.h>
int motorPWM = 5,motorDirc = 4,P_A1 = 2, P_B1 = 3;
float pos=0,angle=0;
double out=0,Ptime=0,Ctime=0,Etime=0,pErr=0,prevErr=0,intErr=0,diffErr=0;
double kp = 5,ki = 5,kd = 0.2;
long long count=0;
Timer mytime;//creating an object from class timer
void setup() {
  Serial.begin(11520);//begining the serial monitor
  pinMode(motorPWM,OUTPUT);//declaring the pins mode
  pinMode(motorDirc,OUTPUT);
  pinMode(P_A1,INPUT_PULLUP);
  pinMode(P_B1,INPUT_PULLUP);
  attachInterrupt(P_A1,ISRA1,CHANGE);//declaring the interrupt for the A and B pins from the encoder
  attachInterrupt(P_B1,ISRB1,CHANGE);
  mytime.every(10,controll);//using timer lib to regulate the computing proccess
}
void loop() {
  // put your main code here, to run repeatedly:   NO NEED
}
void controll(){
  if(Serial.available()){//reading from Serial if available
    pos=Serial.read();//Read
  } 
  Ctime = millis();//get current time in millie second
  Etime =Ctime - Ptime;//compute time elapsed from previous Time and current time
  pErr= pos - angle;//compute proportional error in degree
  intErr += pErr * Etime;//compute integral error
  diffErr = (pErr - prevErr)/Etime;//compute derivative error
  out = kp*pErr + ki*intErr + kd*diffErr;//PID output by summing the proportonal and integral and diffrential Result multiplied by the Coff.              
  prevErr = pErr;//Store current error in other Var to get the Diff error next cycle
  Ptime = Ctime;//Store previous time to get elapsed time next cycle
  if((pErr>2)||(pErr<-2)){//if the error out of margin apply the result to the PWM output
    if(out>0){//if the value is +ve so turn the motor in +ve Direction
      digitalWrite(motorDirc,LOW);
      analogWrite(motorPWM,out);
    }
    else{//if negative turn the motor in -ve direction
      digitalWrite(motorDirc,HIGH);
      analogWrite(motorPWM,out*-1);
    }                                       
  }
  else{//if the position within the margin so stop the motor
    analogWrite(motorPWM,0);
  }
}
void ISRA1(){//interrupt service routine for A pin from Encoder
  if(digitalRead(P_A1) !=digitalRead(P_B1))
    count++;
   else
    count--;
   angle=(count*360)/2400;//calculate the angle from encoder counter
}
void ISRB1(){//interrupt service routine for B pin from Encoder
  if(digitalRead(P_A1) ==digitalRead(P_B1))
    count++;
   else
    count--;
   angle=(count*360)/2400;//calculate the angle from encoder counter
}
