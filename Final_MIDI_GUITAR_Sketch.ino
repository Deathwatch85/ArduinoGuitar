// MIDI GUITAR PROJECT
// Final Sketch
// Project Audio with Arduino
// Author Marco Schmandt
#include <Bounce2.h>
#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

// Neck
int pinGreen  = 13;
int pinRed    = 12;
int pinYellow = 11;
int pinBlue   = 10;
int pinOrange =  9;
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
  Serial.begin(57600);
  MIDI.begin();
  
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
  // Neck
  digitalWrite(pinGreen, 1);
  int valGreen = digitalRead(pinGreen);
  if(valGreen == 0) { MIDI.sendNoteOn(127, 110, 16);
                      delay(100);
                      MIDI.sendNoteOff(127, 0, 16); 
                    };
  
  digitalWrite(pinRed, 1);
  int valRed = digitalRead(pinRed);
  if(valRed == 0) { Serial.println("red"); };
  
  digitalWrite(pinYellow, 1);
  int valYellow = digitalRead(pinYellow);
  if(valYellow == 0) { Serial.println("yellow"); };
  
  digitalWrite(pinBlue, 1);
  int valBlue = digitalRead(pinBlue);
  if(valBlue == 0) { Serial.println("blue"); };
  
  digitalWrite(pinOrange, 1);
  int valOrange = digitalRead(pinOrange);
  if(valOrange == 0) { Serial.println("orange"); };
  
  double slide = constrain(analogRead(pinSlider), 0, 680);
  slide = map(slide, 0, 680, 0, 100);
  
  // Pick Switch
  int pupVal = digitalRead(pickUp);
  int pdnVal = digitalRead(pickDown);
  
  digitalWrite(pickUp, 1);
  digitalWrite(pickDown, 1);
  
  if(pupVal == 0) {  };
  if(pdnVal == 0) {  };
  delay(150);
  
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



