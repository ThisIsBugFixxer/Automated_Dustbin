#include <Servo.h>
Servo servo1;
int echoPin=6;
int trigPin=7;
long distance;
long duration;
 
void setup() 
{
  Serial.begin(9600);
  servo1.attach(9); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);// put your setup code here, to run once:
}
 
void loop() {

  boolean p=false;
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*(0.0343/2); //consider 0.034 if it doesnt work [ FOR ERROR CHECK THIS ]
  
  Serial.println(distance);
  servo1.write(0);
  
  if(distance <= 8){
  servo1.write(100);
  p=true;
  delay(2000); // this will keep the lid open for 2 seconds , but if we keep delay in next if block it will delay the dectiting time of the ultrasonic sensor.  
  // servo1.write(0); this wont work as it will need the initial condition to stisfy.
  
  }
  if(p==true || distance >=8) {
    
    servo1.write(0);
    p=false;
    Serial.println("coming back");
    
  }
}
