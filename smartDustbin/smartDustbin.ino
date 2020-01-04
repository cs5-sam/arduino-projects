#include<Servo.h>
Servo servo_10;
int inches = 0;

int cm = 0;
int c = 0;
int pos = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  servo_10.attach(10);

}

void loop()
{
  
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  
  inches = (cm / 2.54);
  if(cm<=100&&c==0){
    digitalWrite(12,LOW);
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(11, LOW);
    servo_10.write(90);
    c = 1;
  }
  if(cm>100&&c==1){
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    servo_10.write(0);
    c=0;
  }
  
  delay(200); 
}
