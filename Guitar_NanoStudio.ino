l#include <Bounce2.h>

// Neck
int pinGreen  = 13; //R2
int pinRed    = 12; //O
int pinYellow = 11; //Tri
int pinBlue   = 10; //Cross
int pinOrange =  9; //Squ
int pinSlider = A0;
Bounce bouncer1  = Bounce();
Bounce bouncer2  = Bounce();
Bounce bouncer3  = Bounce();
Bounce bouncer4  = Bounce();
Bounce bouncer5  = Bounce();
Bounce bouncer6  = Bounce();
Bounce bouncer7  = Bounce();
Bounce bouncer8  = Bounce();
Bounce bouncer9  = Bounce();
Bounce bouncer10 = Bounce();
Bounce bouncer11 = Bounce();

// Pick Switch
int pickUp    =  8;
int pickDown  =  7;

// Direction Controls
int up        =  6;
int down      =  5;
int left      =  4;
int right     =  3;

// Tremolo
int tremolo   = A1;



void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(pinGreen, INPUT);
  pinMode(pinRed, INPUT);
  pinMode(pinYellow, INPUT);
  pinMode(pinBlue, INPUT);
  pinMode(pinOrange, INPUT);
  pinMode(pickUp, INPUT);
  pinMode(pickDown, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  bouncer1  .attach(pinGreen);
  bouncer2  .attach(pinRed);
  bouncer3  .attach(pinYellow);
  bouncer4  .attach(pinBlue);
  bouncer5  .attach(pinOrange);
  bouncer6  .attach(pickUp);
  bouncer7  .attach(pickDown);
  bouncer8  .attach(up);
  bouncer9  .attach(down);
  bouncer10 .attach(left);
  bouncer11 .attach(right);
  
  bouncer1  .interval(5);
  bouncer2  .interval(5);
  bouncer3  .interval(5);
  bouncer4  .interval(5);
  bouncer5  .interval(5);
  bouncer6  .interval(5);
  bouncer7  .interval(5);
  bouncer8  .interval(5);
  bouncer9  .interval(5);
  bouncer10 .interval(5);
  bouncer11 .interval(5);
}

void loop() {
  digitalWrite(pinGreen, 1);
  int valGreen = digitalRead(pinGreen);
  if(valGreen == 0) { 
                      Keyboard.press(0x71); // q 
                    };
  
  digitalWrite(pinRed, 1);
  int valRed = digitalRead(pinRed);
  if(valRed == 0) { 
                    Keyboard.press(0x77); // w 
                  };
  
  digitalWrite(pinYellow, 1);
  int valYellow = digitalRead(pinYellow);
  if(valYellow == 0) { 
                       Keyboard.press(0x65); // e 
                     };
  
  digitalWrite(pinBlue, 1);
  int valBlue = digitalRead(pinBlue);
  if(valBlue == 0) { 
                     Keyboard.press(0x72); // r 
                   };
  
  digitalWrite(pinOrange, 1);
  int valOrange = digitalRead(pinOrange);
  if(valOrange == 0) { 
                       Keyboard.press(0x74); // t
                     };
  
  double slide = constrain(analogRead(pinSlider), 0, 680);
  slide = map(slide, 0, 680, 0, 100);
  
  
  if(slide <= 100) { Keyboard.press(0x7a); }// z
  else if(slide <= 80) { Keyboard.press(0x75); }// u
  else if(slide <= 60) { Keyboard.press(0x69); }// i
  else if(slide <= 40) { Keyboard.press(0x6f); }// o
  else if(slide <= 20) { Keyboard.press(0x70); }// p
  
  // Pick Switch
  int pupVal = digitalRead(pickUp);
  int pdnVal = digitalRead(pickDown);
  
  digitalWrite(pickUp, 1);
  digitalWrite(pickDown, 1);
  
  if(pupVal == 0) { Keyboard.releaseAll(); };
  if(pdnVal == 0) { Keyboard.release(0x79); };
  
  
  // Direction Controls
  digitalWrite(up, 1);
  int upVal = digitalRead(up);
  if(upVal == 0) {  };
  
  digitalWrite(down, 1);
  int downVal = digitalRead(down);
  if(downVal == 0) {  };
  
  digitalWrite(left, 1);
  int leftVal = digitalRead(left);
  if(leftVal == 0) {  };
  
  digitalWrite(right, 1);
  int rightVal = digitalRead(right);
  if(rightVal == 0) {  };
  
  // Tremolo
  int tremVal = analogRead(tremolo);
  tremVal = constrain(tremVal, 335, 682);
  tremVal = map(tremVal, 335, 682, 0, 100);
  

}
