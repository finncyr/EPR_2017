
int irPin = 13;

void setup() {
pinMode(irPin, OUTPUT); 
}

void loop() {
digitalWrite(irPin, HIGH);
delay(250);
digitalWrite(irPin, LOW);
delay(250);
}
