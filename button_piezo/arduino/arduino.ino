/* Melody
 * (cleft) 2005 D. Cuartielles for K3
 *
 * This example uses a piezo speaker to play melodies.  It sends
 * a square wave of the appropriate frequency to the piezo, generating
 * the corresponding tone.
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note 	frequency 	period 	timeHigh
 * c 	        261 Hz 	        3830 	1915
 * d 	        294 Hz 	        3400 	1700
 * e 	        329 Hz 	        3038 	1519
 * f 	        349 Hz 	        2864 	1432
 * g 	        392 Hz 	        2550 	1275
 * a 	        440 Hz 	        2272 	1136
 * b 	        493 Hz 	        2028	1014
 * bflat                                985
 * C	        523 Hz	        1912 	956
 *
 * http://www.arduino.cc/en/Tutorial/Melody
 */

int birthdayButtonPin = 2;
int childButtonPin = 3;
int speakerPin = 9;
int ledPin = 13;


// Notes with their tonal length
char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'B', 'b', 'C' };
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1075, 1014, 956 };

void rest(int length)
{
  delay(length);
}

void playChildOfGod()
{
  int length = 21;
  char notes[] = "gccccdefgaegggagfecdc"; // a space represents a rest
  int beats[] = { 2,1,1,1,1,1,1,1,1,1,4,2,2,1,1,1,1,1,1,1,4 };
  int tempo = 180;

  playSong(length, notes, beats, tempo);
}

void playHappyBirthday()
{
  int length = 25;
  char notes[] = "ccdcfeccdcgfccCafedBBafgf"; // a space represents a rest
  int beats[] = { 1,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,2 };
  int tempo = 180;

  playSong(length, notes, beats, tempo);
}

void playSong(int length, char* notes, int* beats, int tempo)
{
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ')
      rest(beats[i] * tempo);
    else
      playNote(notes[i], beats[i] * tempo);

    // pause between notes
    delay(tempo / 2);
  }
}

void playTone(int tone, int duration)
{
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration)
{
  digitalWrite(ledPin, HIGH);
  for (int i = 0; i < 9; i++)
    if (names[i] == note)
      playTone(tones[i], duration);
  digitalWrite(ledPin, LOW);
}

void setup()
{
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(birthdayButtonPin, INPUT);
  pinMode(childButtonPin, INPUT);
}

void loop()
{
  if (digitalRead(birthdayButtonPin) == LOW)
    playHappyBirthday();
  else if (digitalRead(childButtonPin) == LOW)
    playChildOfGod();
}

