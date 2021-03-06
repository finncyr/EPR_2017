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

 
void setup()
{
  // Einrichtung Servo Pins
  ServoL.attach(servoPinL);
  ServoR.attach(servoPinR);

  // Einrichtung Joystick
  pinMode(SW_pin, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);


}
 
void loop()
{
valY = analogRead(Y_pin);
valY = map(valY, 0, 1023, 0, 180);    //Konvertierung Analog Joystick -> Gradmaß

valX = analogRead(X_pin);
valX = map(valX, 0, 1023, 0, 180);    //Konvertierung Analog Joystick -> Gradmaß

if(valY > 95 || valY < 85){           //if Schleife für Toleranz +-5° in Y Richtung
    ServoL.write(abs(valY-180));
    ServoR.write(valY);
    }
else if(valX > 95 || valX < 85){      //if Schleife für Toleranz +-5° in X Richtung
    ServoL.write(valX);
    ServoR.write(valX);
    }
else{                                 //"Stop" Schleife
    ServoL.write(90);
    ServoR.write(90);
    }

  // Monitoring von x und y Werten
  Serial.print(valX);
  Serial.print("  ");
  Serial.println(valY);
   
  delay(5);

  

}
