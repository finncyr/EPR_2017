char var;

void setup() {

  Serial.begin(9600);
}
 

void loop() 
{
 var = Serial.read();

  Serial.println(var);


}
