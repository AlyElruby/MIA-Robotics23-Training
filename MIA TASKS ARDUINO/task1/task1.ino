
unsigned long mytimee=0;
int motor1 = 3;//motor1 control signal on pin 3 cuz PWM pin
int motor2 = 4;//motor2 control signal on pin 4
int led=5;//the led is connected to pin 5 cuz PWM pin
int button1=2;//the button is connected on pin 2 cuz it's interrupt pin
int moisture=A0;//moiture sensor is connected to pin A0
int force=A1;//Force sensor is connected to pin A1
int moistureval;//variable to storw the reading from moisture sensor
int forceval;//variable to store the reading of force sensor
int counter =0;//variable to store how many you push the button

void count(void){//declaring and defining a function to increasing the counter and to turn on motor2 
  counter++;//inc counter
  Serial.println(counter);//disp the value of counter
  digitalWrite(motor2,HIGH);//turn on the motor2
   mytimee= millis();
   
}
void motoroff(void){//function to turn off the motor
  digitalWrite(motor2,LOW);//write low at motor2 pin
}
void setup() {
  Serial.begin(9600);//to use the serial monitor
  pinMode(led,OUTPUT);//define the in and out ports
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(button1,INPUT);
  attachInterrupt(digitalPinToInterrupt(button1),count,FALLING);//using an interrupt to the button1 pin
}
void loop() {
  moistureval=analogRead(moisture);//reading the value from the moisture sensor
  analogWrite(motor1,map(moistureval,0,1023,255,0));//the moisture sensor gives 1023 when it's 0% moist in soil so we mapping it to 0 to 255 to output it on PWM inversly so when it read 0 that mean the soil is 100% moist so the motor turn off
  forceval=analogRead(force);//read the force sensor reading value
  analogWrite(led,map(forceval,0,1023,255,0));//the force sensor gives 0 when it read 0 force and 1023 when max force so we map it inversly so when it read max the led will be off
  if(millis()>=mytimee+10000){
    motoroff();
   }
}
