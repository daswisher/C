//Simple temperature sensor using only a tmp36 connected to analog 0 on arduinoUno r3
int tempPin = 0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
 float temp = (analogRead(tempPin)* 0.004882814);
 temp = (temp - .5) * 100;
 Serial.println(temp);
 delay(60000);
}

