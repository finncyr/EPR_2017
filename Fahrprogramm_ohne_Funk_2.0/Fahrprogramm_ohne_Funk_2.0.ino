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
  // Auslesen des Joysticks
  
valY = analogRead(Y_pin);
valY = map(valY, 0, 1023, 0, 180);    //Konvertierung Analog Joystick -> Gradmaß

valX = analogRead(X_pin);
valX = map(valX, 0, 1023, 0, 180);    //Konvertierung Analog Joystick -> Gradmaß

  //Fallunterscheidungen für Fahrprogramm

if(valX > 120 && valY > 120){         // Fallunterscheidung: Vorwärts-Rechts
    ServoL.write(180);
    ServoR.write(80); 
}
else if(valX > 120 && valY < 20){     // Fallunterscheidung: Rückwärts-Rechts
    ServoL.write(0);
    ServoR.write(100);
  }
else if(valX < 20 && valY > 120){     // Fallunterscheidung: Vorwärts-Links
    ServoL.write(100);
    ServoR.write(0);
  }
else if(valX < 20 && valY < 20){      // Fallunterscheidung: Rückwärts-Links
    ServoL.write(80);
    ServoR.write(180);
  }

else if(valY > 95 || valY < 85){      //if Schleife für Toleranz +-5° in Y Richtung & Fallunterscheidung Vorwärts/Rückwärts
    ServoL.write(abs(valY-180));          
    ServoR.write(valY);
    }
else if(valX > 95 || valX < 85){      //if Schleife für Toleranz +-5° in X Richtung & Fallunterscheidung Links/Rechts
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
