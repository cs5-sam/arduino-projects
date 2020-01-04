#include <LiquidCrystal.h>

int sec = 0;
int min  =0;
int hr = 0;
int c = 0;
int timerMin = 1; // set minutes for timer
int timerHr = 0;  // set hours for timer
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
 
  lcd.begin(16, 2);
  pinMode(8,OUTPUT);
}

void loop() {
  
  c = millis()/1000;
  sec = c%60;
  min = (c/60)%60;
  hr = (c/3600)%24;
  lcd.print(hr);
  lcd.print(":");
  lcd.print(min);
  lcd.print(":");
  lcd.print(sec);
  delay(1000);
  lcd.clear();
  if( min == timerMin){
    tone(8,3000,60000);
  }
  else if(min != timerMin){
    noTone(8);
  }
}
