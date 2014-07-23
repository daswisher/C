int sensorPin = 0;
int ledPin = 11;
int sensorValue = 0;
int motorPin = 10;
void setup() {
  //Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
  pinMode(motorPin, OUTPUT); 
}

void loop() {
  sensorValue = analogRead(sensorPin);   
  sensorValue = map(sensorValue, 0, 900, 0, 255); 
  sensorValue = constrain(sensorValue, 0, 255); 
  analogWrite(motorPin, sensorValue); 
  analogWrite(ledPin, sensorValue); 
  //Serial.println(sensorValue);               
}
