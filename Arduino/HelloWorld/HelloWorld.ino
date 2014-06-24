/*This code requires no external components to run*/
/*If desired, it is possible to use a separate LED. I used a 5mm LED connected to pin 13 with a 560 ohm resistor in between, then ran a wire from the negative terminal on the led to the ground port on the arudino board*/
int LED = 13;

void setup(){
  pinMode(LED, OUTPUT);
}

void loop(){
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
}
