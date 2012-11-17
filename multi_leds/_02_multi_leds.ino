int ledPins[] = {2,3,4,5,6,7,8,9};

void setup()
{
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(ledPins[j], i == j ? HIGH : LOW);
    }
    delay(1000);
  } 
}
