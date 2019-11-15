int sensorValue = 0;
int c=0;
int tuneFreq=3000;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
   pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(9, HIGH);
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);   
  if(sensorValue<165&&c==0)
  {
    tone(12, tuneFreq, 250);
    c=1;
    tuneFreq+=500;
    if(tuneFreq>5000)
      tuneFreq=3000;
  }
  else if(sensorValue>200)
  {
    c=0;
  }
}
