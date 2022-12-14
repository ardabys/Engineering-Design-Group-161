#include <Servo.h>

Servo servoMetal;
Servo servoPlastic;
Servo servoOther;  

void setup() {
  pinMode(13, OUTPUT); //LED1
  pinMode(8, INPUT);  //METAL
  pinMode(7, INPUT);  //IR
  pinMode(6, OUTPUT); //LED2
  servoMetal.attach(9); //Servo 1 
  servoPlastic.attach(10); //Servo 2
  servoOther.attach(11); //Servo 3
  Serial.begin(9600);
  
}

void loop() {
    
  if(digitalRead(7) == LOW){  //waste is detected by IR
    digitalWrite(13, HIGH);   //Turn LED1 ON
    digitalWrite(6, HIGH);    //Turn LED2 ON
    Serial.println("Detecting...");
    delay(1000);
    
    if( digitalRead(8) == LOW ){ //metal is detected
      Serial.println( "Metal detected! Beginning sorting." );
      delay(1000);
      
      //TILTING FOR METAL
      servoOther.writeMicroseconds(1000);
      servoPlastic.writeMicroseconds(1000);
      delay(2500); //run the servos for 3000 seconds
      servoOther.writeMicroseconds(1500);
      servoPlastic.writeMicroseconds(1500);
      delay(2000); //wait for the waste to slide
      servoOther.writeMicroseconds(2000);
      servoPlastic.writeMicroseconds(2000);
      delay(2500);  //run the servos for 3000 seconds
      servoOther.writeMicroseconds(1500);
      servoPlastic.writeMicroseconds(1500);
      
      Serial.println("Done.");  //prints done when the metal is in the right bin and the trash can is ready to receive new waste
      return;
       }
       
       else{
         Serial.println( "Non-metal waste. Continuing detection...");
         delay(1000);
       }
    
  

//Plastic detecting sequence

    Serial.print("Light level = ");
    Serial.println(analogRead(A0));    //prints out the light level
    delay(1000);
    int light_level =  analogRead(A0);
      

      //NON PLASTIC WASTE DETECTION
      
    if(light_level > 800) {  //treshold to be determined by testing
      Serial.println("Non plastic waste detected. Beginning sorting.");

      //TILTING FOR NON PLASTIC
      
      servoPlastic.writeMicroseconds(1000);
      servoMetal.writeMicroseconds(1000);
      delay(2500); //run the servos for 3000 seconds
      servoPlastic.writeMicroseconds(1500);
      servoMetal.writeMicroseconds(1500);
      delay(2000); //wait for the waste to slide
      servoMetal.writeMicroseconds(2000);
      servoPlastic.writeMicroseconds(2000);
      delay(2500);  //run the servos for 3000 seconds
      servoMetal.writeMicroseconds(1500);  //stop servos
      servoPlastic.writeMicroseconds(1500);
      Serial.println("Done.");
      return;
    }
    
    
      //PLASTIC WASTE DETECTED
      
    else {
      Serial.println("Plastic waste detected! Beginning sorting.");
      servoOther.writeMicroseconds(1000);
      servoMetal.writeMicroseconds(1000);
      delay(2500); //run the servos for 3000 seconds
      servoOther.writeMicroseconds(1500);
      servoMetal.writeMicroseconds(1500);
      delay(2000); //wait for the waste to slide
      servoOther.writeMicroseconds(2000);
      servoMetal.writeMicroseconds(2000);
      delay(2500);  //run the servos for 3000 seconds
      servoMetal.writeMicroseconds(1500); //Stop servos
      servoOther.writeMicroseconds(1500);
      Serial.println("Done.");
      return;
    }
  }
    else {  //no waste is detected by IR
      digitalWrite(13, LOW);   //Turn LED1 OFF
      digitalWrite(6, LOW);    //Turn LED2 OFF
    }
}
