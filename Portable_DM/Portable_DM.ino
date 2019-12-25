#include<LiquidCrystal.h>

#define RS 7
#define E 6
#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define TRIG 9
#define ECHO 8

LiquidCrystal FC(RS,E,D4,D5,D6,D7);

float cm = 0, in = 0;

void setup(){
  FC.begin(16,2);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop(){
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  cm = 0.01723 * pulseIn(ECHO, HIGH);
  in = (cm/2.54);
  FC.print("cm: ");
  FC.setCursor(0,1);
  FC.print(cm);
  delay(100);
  FC.clear();
  
}
