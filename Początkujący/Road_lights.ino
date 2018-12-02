void setup() {
  pinMode(5,INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}

void loop() {
  if(digitalRead(5) == LOW)
  {
    delay(1000);
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(2000);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
  }
}
