#include <Servo.h>

// Arduino pin numbers Joystick
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 1; // analog pin connected to X output
const int Y_pin = 0; // analog pin connected to Y output

// Arduino pin numbers Servo
const int servoPinL = 10;         // Linker Servo
const int servoPinR = 11;         // Rechter Servo
const int center   = 3;           // Toleranz Servo

// Definition Servos
Servo ServoL;
Servo ServoR;

// Variablenumformung

int valX = 440;
int valY = 440;
int valB = 0;

// Datenempfang
int incoming;
boolean empfbest;


boolean Test = true;

void setup() {
  // put your setup code here, to run once:
    ServoL.attach(servoPinL);
  ServoR.attach(servoPinR);
}

void loop() {
  // put your main code here, to run repeatedly:

if(/*HIER ABFRAGE W*/){      
    ServoL.write(180); 
    ServoR.write(0);         
  }
  else if(/*HIER ABFRAGE S*/){      
    ServoL.write(0); 
    ServoR.write(180);         
  }
    else if(/*HIER ABFRAGE A*/){      
    ServoL.write(180); 
    ServoR.write(180);         
  }
    else if(/*HIER ABFRAGE D*/){      
    ServoL.write(0); 
    ServoR.write(0);         
  }
    else if(Test = true){      
    ServoL.write(90); 
    ServoR.write(90);         
  }
}
