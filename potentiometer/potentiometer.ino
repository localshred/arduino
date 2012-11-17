int sensorPin = 0;
int ledPin = 9;
int sensorValue = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  sensorValue = analogRead(sensorPin) / 4;
  analogWrite(ledPin, sensorValue);
}
  
