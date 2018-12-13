void setup() {
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(4,INPUT);
}

void loop() {
  if(Serial.available())
  {
    char dane = Serial.read();
    if(dane == '1')
    {
      digitalWrite(7,HIGH);
    }
    if(dane == '0')
    {
      digitalWrite(7,LOW);
    }
  }
  if(digitalRead(4)==0)
  {
    Serial.println("Guzik wcisniety!");
  }
}
