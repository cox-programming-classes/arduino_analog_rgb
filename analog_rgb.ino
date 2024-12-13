#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6
#define POT_PIN A0 // Analog Pin 0

void setup() 
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  // Analog Pins do not need a pinMode set.
}

void loop() 
{
  // reads a value between 0 and 1023 (2^10 - 1)
  int potValue = analogRead(POT_PIN);

  // scale the value of the reading so that it will be
  // a valid brightness for the LED.
  /*
  int brightness = map(potValue, 0, 1023, 0, 255);

  analogWrite(RED_PIN, brightness);
  analogWrite(GREEN_PIN, brightness);
  analogWrite(BLUE_PIN, brightness);

  delay(50);
  */
  int timespan = potValue * 5;

  fadeIn(220, 0, 255, timespan);
  fadeOut(220, 0, 255, timespan);

  delay(50);
}

// Sets the LED Color to a given RGB value.
void setLEDColor(int red, int green, int blue)
{
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

// Turn the LED Off.
void clearLED() 
{
  setLEDColor(0,0,0);
}

// Fade into a chosen color over a given timespan.
void fadeIn(int red, int green, int blue, int milliseconds)
{
  int r = 0, g = 0, b = 0;
  for(int i = 1; i <= 10; i++)
  {
    setLEDColor(r, g, b);
    delay(milliseconds / 10);
    r = (i/10.0) * red;
    g = (i/10.0) * green;
    b = (i/10.0) * blue;
  }
}

// Fade out from a chosen color over a given timespan.
void fadeOut(int red, int green, int blue, int milliseconds)
{
  int r = red, g = green, b = blue;
  for(int i = 9; i >= 0; i--)
  {
    setLEDColor(r, g, b);
    delay(milliseconds / 10);
    r = (i/10.0) * red;
    g = (i/10.0) * green;
    b = (i/10.0) * blue;
  }
}

void fadeLightBlueToDarkPurple()
{
  int r = 120, g = 180, b = 255;
  for(int i = 1; i <= 10)
  {
    setLEDColor(r, g, b);
    delay(2500/10);
    r = ((80-120)/2500) * ((2500/10)*i) + 120;
    g = ((0-180)/2500) * ((2500/10)*i) + 120;
    r = ((90-255)/2500) * ((2500/10)*i) + 255;
  }
}
