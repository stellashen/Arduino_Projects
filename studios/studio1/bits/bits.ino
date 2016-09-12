/*
 * Programming and Bit Manipulation studio
 */
#include <Arduino.h>
#include <Wire.h>
#include "bits.h"


void setup() {  
  
  Serial.begin(9600);

  //unsigned a = 32770;    //Change This Number
  unsigned a = 100; 


  //SHIFTING
  unsigned b = shiftLeft(a);
  unsigned c = shiftRight(a);
  unsigned d = invert(a);

  //PRINTING
  pprint("INPUT",a);
  pprint("LEFTSHIFT",b);
  pprint("RIGHTSHIFT",c);
  pprint("INVERSE",d);

}


void loop() {
  
}

