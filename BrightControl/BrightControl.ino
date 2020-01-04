#define LED 9

int ldr_value;
int convert;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  ldr_value = analogRead(A0);
  convert = map(ldr_value,0,1023,0,255);
  analogWrite(LED,convert);
}
