void setup() {
  pinMode(6, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(6) == LOW){
  digitalWrite(13, HIGH);
  delay(10);
  }
  else {
    digitalWrite(13,LOW);
    delay(10);
  }
  
}
