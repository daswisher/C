int ledPins[]={2,3,4,5,6,7,8,9};
int delayTime=100;
void setup(){
   for(int i = 0; i < 8; i++){
     pinMode(ledPins[i], OUTPUT);
   }
}

void loop(){
   /*
   digitalWrite(ledPins[0], HIGH);
   delay(delayTime);  
   digitalWrite(ledPins[1], HIGH);
   delay(delayTime);  
   digitalWrite(ledPins[2], HIGH);
   delay(delayTime);  
   digitalWrite(ledPins[3], HIGH);
   delay(delayTime);  
   digitalWrite(ledPins[4], HIGH);
   delay(delayTime);  
   digitalWrite(ledPins[5], HIGH);
   delay(delayTime);  
   digitalWrite(ledPins[6], HIGH);
   delay(delayTime);  
   digitalWrite(ledPins[7], HIGH);
   delay(delayTime);   
   digitalWrite(ledPins[0], LOW);
   delay(delayTime);  
   digitalWrite(ledPins[1], LOW);
   delay(delayTime);  
   digitalWrite(ledPins[2], LOW);
   delay(delayTime);  
   digitalWrite(ledPins[3], LOW);
   delay(delayTime);  
   digitalWrite(ledPins[4], LOW);
   delay(delayTime);  
   digitalWrite(ledPins[5], LOW);
   delay(delayTime);  
   digitalWrite(ledPins[6], LOW);
   delay(delayTime);  
   digitalWrite(ledPins[7], LOW);
   delay(delayTime);
   */
   //Using for loops is a cleaner way to write the code
   for(int j=0; j<8; j++){
     digitalWrite(ledPins[j], HIGH);
     delay(delayTime);
   }
   for(int k=0; k<8; k++){
     digitalWrite(ledPins[k], LOW);
     delay(delayTime);
   }
}

