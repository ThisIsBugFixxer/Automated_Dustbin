int echopin=6;
int trigpin=7;
int highpin=5;


long t;   // time.


void setup() {
  // put your setup code here, to run once:
  

pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(highpin, HIGH);

digitalWrite(trigpin, LOW);
delayMicroseconds(2);

digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);

t=pulseIn(echopin, HIGH);
int s=t*0.0171;   // v=s/t, s=vt, here speed of sound (v)=342 m/s=0.0342 cm/s, and it is divided by 2 ie 0.0342/2 as time tsken is double as for before it hits object and then it returns back.

//Serial.println("distance of object");
//Serial.println(t);
Serial.println("distance:  ");
Serial.print(s);
Serial.print(" cm    ");

float inch=s/2.54;
Serial.print(inch);
Serial.println(" inch         ");
}
