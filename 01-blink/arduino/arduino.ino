int ledPin = 9;

void setup()
{
}

void loop()
{
  for (int i = 0; i <= 255; i += 5) {
    analogWrite(ledPin, i);
    delay(30);
  }
  for (int i = 255; i >= 0; i -= 5) {
    analogWrite(ledPin, i);
    delay(30);
  }
}
