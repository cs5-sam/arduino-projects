int ldr_value = 0;
int c = 0;
int tunefreq = 3000;

void setup(){
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  ldr_value = analogRead(A0);
  Serial.println(ldr_value);
  digitalWrite(9,HIGH);
  if(ldr_value<165 && c == 0){
    tone(12, tunefreq,250);
    c = 1;
    tunefreq+=300;
    if(tunefreq>5000){
      tunefreq = 3000;
    }
  }
  else if(ldr_value>200){
    c = 0;
  }
  
}
