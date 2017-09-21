#include <Servo.h>

int var;

Servo servolinks;
Servo servorechts;

void setup() 
{
  Serial.begin(9600);

  servorechts.attach(11);
  servolinks.attach(10);
}
 

void loop() 

{
  while ((var = Serial.read())!= -1)
  {
   
    
    //W
    if (var == 87)
    {
      servolinks.write(180);
      servorechts.write(0);
      Serial.println(var);
    }
    //w
    if (var == 119)
    {
      servolinks.write(95);
      servorechts.write(85);
      Serial.println(var);
    }

    //A
    if (var == 65)
    {
      servolinks.write(83);
      servorechts.write(83);
      Serial.println(var);
    }
    //a
    if (var == 97)
    {
      servolinks.write(88);
      servorechts.write(88);
      Serial.println(var);
    }

    //S
     if (var == 83)
     {
      servolinks.write(0);
      servorechts.write(180);
      Serial.println(var);
     }
    //s
    if (var == 115)
    {
      servolinks.write(85);
      servorechts.write(95);
      Serial.println(var);
    }

    //D
    if (var == 68)
    {
      servolinks.write(97);
      servorechts.write(97);
      Serial.println(var);
    }
    //d
    if (var == 100)
    {
      servolinks.write(92);
      servorechts.write(92);
      Serial.println(var);
    }
    
    //E
    else if (var == 69)
    {
      servolinks.write(90);
      servorechts.write(90);
      Serial.println(var);
    }
  }
}


