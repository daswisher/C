#include <Servo.h> 
Servo myservo;
int sensorPin = 0;
int sensorValue = 82; //This will center it and allow for up/down elevon control
void setup() {
  //Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  sensorValue = analogRead(sensorPin);   
  sensorValue = map(sensorValue, 0, 900, 0, 255); 
  sensorValue = constrain(sensorValue, 0, 160); //My servo has issues with anything above this value due to sensor bounce and a limitation with my servo positioning at the 180th degree 
  //Serial.println(sensorValue); 
  myservo.write(sensorValue);
  delay(30); //30ms is enough to make sure that the servo is responsive, but doesn't burn itself out
}
