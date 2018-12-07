#include <Servo.h>

#define echoPin 6 
#define trigPin 7 
#define rightServoPin 8
#define leftServoPin 9

Servo rightServo;
Servo leftServo;
long randNumber;

void setup(){
  Serial.begin(9600); // begin serial communitication  
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  rightServo.attach(rightServoPin); // set the right servo pin to 8
  leftServo.attach(leftServoPin); // set the left servo pin to 9
  randomSeed(analogRead(7));
}

void loop(){
  long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  // clear the trig pin
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  
  digitalWrite(trigPin, HIGH); // set the trigger pin on HIGH for 10us
  delayMicroseconds(10); //this delay is required as well
  
  digitalWrite(trigPin, LOW); // Reads the echo pin signal 
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
    
   if(distance < 20){ // If obstacle is closer than 20cm away, turn
    
      randNumber = random(100); // generate random number 1 or 2
      
      if(randNumber > 50){ // turn right if 1
        rightServo.write(180);
        leftServo.write(180);
        delay(500);
      }
      if(randNumber < 50){ // turn left if 2
        rightServo.write(0);
        leftServo.write(0);
        delay(500);
      }
   }
   else{ // If obstacle is more than 20 cm away, move forward
      rightServo.write(180);
      leftServo.write(0); 
   } 
 delay(100);
}  

  