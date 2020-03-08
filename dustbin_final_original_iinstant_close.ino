// this code works fine but the lid closes recently i.e. the servo comes to 0 very fast, so see the dustbin_final code. it is the main code.

#include <Servo.h>
Servo servo1;
int trigPin = 7;
int echoPin = 6;
long distance;
long duration;
 
void setup() 
{
  Serial.begin(9600);
  servo1.attach(8); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);// put your setup code here, to run once:
}
 
void loop() {


   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*(0.034/2);
  Serial.println(distance);
  servo1.write(0);
  if(distance <= 10){
  servo1.write(90);
  
  }
}
