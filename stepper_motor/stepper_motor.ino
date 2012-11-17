int motorPin = 9;

void setup()
{
  pinMode(motorPin, OUTPUT);
}

void loop()
{
//  motorOnThenOff();
//  motorOnThenOffWithSpeed();
//  motorAcceleration();
}

void motorOnThenOff()
{
  int onTime = 2500;
  int offTime = 1000;
  
  digitalWrite(motorPin, HIGH);
  delay(onTime);
  digitalWrite(motorPin, LOW);
  delay(offTime);
}

void motorOnThenOffWithSpeed()
{
  int onTime = 2500;
  int offTime = 1000;
  
  int offSpeed = 50;
  int onSpeed = 200;
  
  analogWrite(motorPin, onSpeed);
  delay(onTime);
  analogWrite(motorPin, offSpeed);
  delay(offTime);
}

void motorAcceleration(){
  int delayTime = 50; //milliseconds between each speed step
  
  //Accelerates the motor
  for(int i = 0; i < 256; i++){ //goes through each speed from 0 to 255
    analogWrite(motorPin, i);   //sets the new speed
    delay(delayTime);           // waits for delayTime milliseconds
  }
  
  //Decelerates the motor
  for(int i = 255; i >= 0; i--){ //goes through each speed from 255 to 0
    analogWrite(motorPin, i);   //sets the new speed
    delay(delayTime);           // waits for delayTime milliseconds
  }
}

