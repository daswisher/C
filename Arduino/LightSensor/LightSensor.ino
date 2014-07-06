//This is code used to read ambient light from a photoresistor
int lightPin = 0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
 int lightLevel = analogRead(lightPin);
 /*
 //The following is code to map the values to be used to control an led via pwm
 
 lightLevel = map(lightLevel, 0, 900, 0, 255); 
 lightLevel = constrain(lightLevel, 0, 255);
 analogWrite(ledPin, lightLevel); //Setup the ledPin before running this
 */
 Serial.println(lightLevel);
 delay(1000);
}
