int data = 2;
int clock = 3;
int latch = 4;

int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

void setup()
{
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
}

void loop()
{
  int delayTime = 100;
  for (int i = 0; i < 256; i++) {
    updateLEDs(i);
    delay(delayTime);
  }
}

void updateLEDs(int value)
{
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, value);
  digitalWrite(latch, HIGH);
}


