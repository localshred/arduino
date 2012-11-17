int ledDigitalOne[] = {9,10,11};

const boolean ON = LOW;
const boolean OFF = HIGH;

const boolean RED[]      = {ON, OFF, OFF};
const boolean GREEN[]     = {OFF, ON, OFF};
const boolean BLUE[]    = {OFF, OFF, ON};
const boolean YELLOW[]   = {ON, ON, OFF};
const boolean CYAN[]     = {OFF, ON, ON};
const boolean MAGENTA[]  = {ON, OFF, ON};
const boolean WHITE[]    = {ON, ON, ON};
const boolean BLACK[]    = {OFF, OFF, OFF};

const boolean* COLORS[] = {RED, GREEN, BLUE,
                             YELLOW, CYAN, MAGENTA,
                             WHITE, BLACK};
                             
void setup()
{
  for (int i = 0; i < 3; i++) {
    pinMode(ledDigitalOne[i], OUTPUT);
  }
}

void loop()
{
//  for (int i = 0; i < sizeof(COLORS); i++) {
//    setColor(ledDigitalOne, COLORS[i]);
//    delay(1000);
//  }
}

void setColor(int* led, boolean* color)
{
  for (int i = 0; i < 3; i++) {
    digitalWrite(led[i], color[i]);
  }
}

void setColor(int* led, const boolean* color)
{
  boolean tempColor[] = {color[0], color[1], color[2]};
  setColor(led, tempColor);
}

