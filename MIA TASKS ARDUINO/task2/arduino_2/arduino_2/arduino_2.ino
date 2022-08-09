int moisture =A0;
unsigned int moistval;//to store the moist and cuz it's 2 byte only so it will be easier to send
void setup() {
Serial.begin(9600);
}
void loop() {
  if (digitalRead(4))//this is optional just to make sure that it wil be synchronized
{
moistval=analogRead(moisture);
  Serial.write(highByte(moistval));//sending the first byte
  Serial.write(lowByte(moistval));//second byte
  delay(15);
}
}
