int latchPin = 4;
//Pin connected to SH_CP of 74HC595
int clockPin = 3;
////Pin connected to DS of 74HC595
int dataPin = 2;

int clearPin = 8;
void setup() 
{
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clearPin, OUTPUT);
  digitalWrite(clearPin, LOW);
  digitalWrite(clearPin, HIGH);

}

int i = 1;
int LENGTH = 6;
int b[5] = {0};
int h = 1;
void loop() 
{
   for (int j = 2; j < 256; ++j)
{
    int delayTime = 500;
    updateLED (i);
    delay(delayTime);
   
}

} 

void updateLED(int value)
{
digitalWrite(clearPin, LOW);
digitalWrite(clearPin, HIGH);  
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, value);
digitalWrite(latchPin, HIGH);
}

