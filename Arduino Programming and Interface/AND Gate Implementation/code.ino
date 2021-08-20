/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
*/

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(2,LOW);
  digitalWrite(7,LOW);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  
  digitalWrite(2,HIGH);
  digitalWrite(7,LOW);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  
  digitalWrite(2,LOW);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  
  digitalWrite(2,HIGH);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(13,HIGH);
  delay(2000);

}
