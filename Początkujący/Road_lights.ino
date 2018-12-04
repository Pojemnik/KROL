void setup() {
  pinMode(5,INPUT);     //Przycisk
  pinMode(6,OUTPUT);    //led zielony
  pinMode(7,OUTPUT);    //led żółty
  pinMode(8,OUTPUT);    //led czerwony
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}

void loop() {
  if(digitalRead(5) == LOW)
  /*
  Gdy klawisz jest wciśnięty
  (na kółku porównywaliśmy do jedynki,
  ponieważ inaczej podłączaliśmy przycisk)
  */
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
