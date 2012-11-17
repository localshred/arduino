int sensePin = 2;
int ledPin = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  int value = analogRead(sensePin) / 4;
  analogWrite(ledPin, value);
  Serial.println(value);
}
