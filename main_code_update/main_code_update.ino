#include <Servo.h>

Servo servoMetal;
Servo servoPlastic;
Servo servoOther;
int analogValue = analogRead(A5); //LIGHT

void setup() {
  pinMode(13, OUTPUT); //LED
  pinMode(8, INPUT);  //METAL
  pinMode(6, INPUT);  //IR
  servoMetal.attach(9);
  servoPlastic.atach(10);
  servoOther.attach(11);
  Serial.begin(9600);
  
}

void loop() {
    
  if(digitalRead(6) == LOW){  //waste is detected by IR
    digitalWrite(13, HIGH);   //Turn LED ON
    delay(100);
    Serial.println("Detecting...");
    delay(4000);
    
    if( digitalRead(8) == LOW ){ //metal is detected
      Serial.println( "Metal detected! Beginning sorting." );
      delay(1000);
      
      // TILTING FOR METAL
      servoMetal.write(tilting position);
      delay(xxx); wait for the waste to slide
      servoMetal.write(initial position);
      delay(xxx);
      
      Serial.println("Done.");  //prints done when the metal is in the right bin and the trash can is ready to receive new waste
      return;
       }
       
       else{
         Serial.println( "Non-metal waste. Continuing detection...");
         delay(1000);
       }
    
  

//Plastic detecting sequence

    Serial.print("Light level = ");
    Serial.print(analogValue); 


      ADDITIONAL SCENARIO(too much light --> lid is open)
      This scenario can be implemented as a general check for the program if the lid is open --> no checking)

      if(analogValue > treshold2) {
        println("Please close the lid to begin detection and sorting");
        delay(3000);
        return;
      }
      

      // NON PLASTIC WASTE
    if(analogValue < treshold) {  //treshold to be determined by testing
      serial.println("Non plastic waste detected. Beginning sorting.");

      // TILTING FOR NON PLASTIC
      servoOther.write(tilting position);
      delay(xxx);
      servoOther.write(initial position);
      delay(xxx);
      println("Done.");
      return;
    }
    
    
      // PLASTIC WASTE
    else {
      Serial.println("Plastic waste detected! Beginning sorting.");
      servoPlastic.write(tiltiing position);
      delay(xxx);
      servoPlastic.write(initial position);
      delay(xxx);
      println("Done.");
      return;
    }

}


    else {  //no waste is detected by IR
      digitalWrite(13, LOW);
      delay(10);
    }
}
