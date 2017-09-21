#include <Servo.h>

int var;

int IRSensorPin=A0;
//int LedPin=12;
const int buzzer = 9;
int sensorValue=0;
int IRLedPin=7;
int ledState = LOW;                      // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
long OnTime = 40;                        // milliseconds of on-time
long OffTime =40 ;                       // milliseconds of off-time

Servo servolinks;
Servo servorechts;

void setup() 
{
  Serial.begin(9600);

  servorechts.attach(11);
  servolinks.attach(10);

  //pinMode(LedPin, OUTPUT);
  pinMode(buzzer,OUTPUT);
  // digitalWrite(LedPin, LOW);
  pinMode(IRLedPin,OUTPUT);
  pinMode(IRSensorPin,INPUT);
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

  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();
  
  if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    ledState = LOW;                   // Turn it off
    previousMillis = currentMillis;   // Remember the time
    digitalWrite(IRLedPin, ledState); // Update the actual LED
  }
  
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   // Remember the time
    digitalWrite(IRLedPin, ledState);    // Update the actual LED
  }
  
  sensorValue=analogRead(IRSensorPin);
  //Serial.println(sensorValue);
  if(sensorValue <1000)
  {
    //digitalWrite(LedPin, HIGH);
    tone(buzzer,880);
    delay(40);
  }
    else if(sensorValue >1000)
  {
    noTone(buzzer);
    //digitalWrite(LedPin, LOW);
  }
  
}


