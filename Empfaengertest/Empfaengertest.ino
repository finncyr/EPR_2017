int incoming;
boolean empfbest;
void setup() 
{
  Serial.begin(9600);
  if(Serial.available()>0) 
  {
    Serial.write("serial Hardware detected");
  }
  else
  {
    Serial.write("ERROR: serial Hardware unavailable");
  }
  Serial.write("setup complete");

}

void loop() 
{
  if(Serial.read()>0)
  {
    incoming = Serial.read();
    empfbest = true;
    Serial.write("recieve Status " + empfbest);
    Serial.print(incoming);
    Serial.print("\r\n");
  }
  
  else
  {
    empfbest = false;
    Serial.write("recieve Status " + empfbest);
  }

}
