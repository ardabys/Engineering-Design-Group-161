void setup() {
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);

  
  
}

void loop() {
  
  int analogValue = analogRead(A5);
  
  if(digitalRead(6) == LOW){
    digitalWrite(13, HIGH);
    delay(100);
    Serial.println("Detecting...");
    delay(3000);
    if( digitalRead(8) == LOW ){
    Serial.println( "Metal detected! Beginning sorting." );
         delay(3000);
         Serial.println("Done.");
         return;
       }
       else{
         Serial.println( "Non-metal waste. Continuing detection...");
         delay(2000);
       }

  //works well until plastic detection
  //to be improved 
    
    Serial.print("Sensing light level = ");
    Serial.print(analogValue);   

   
    if (analogValue < 100) {
      Serial.println(" - Very bright");
      delay(1000);
      Serial.println("Plastic detected! Beginning sorting.");
      delay(3000);
      Serial.println("Done");
      return;
    } else if (analogValue < 200) {
      Serial.println(" - Bright");
    } else if (analogValue < 500) {
      Serial.println(" - Light");
    } else if (analogValue < 800) {
      Serial.println(" - Dim");
      delay(1000);
      Serial.println("Non-plastic. Beginning sorting...");
      delay(3000);
      Serial.println("Done.");
      return;
    } else {
      Serial.println(" - Dark");
    }
    delay(500);
}
    else {
      digitalWrite(13, LOW);
      delay(10);
    }
}
