#include <Arduino.h>


int led = 13;               
int sensor = 2;              
int state = LOW;             
int val = 0;                
const int buzzer = 9;

void setup() {
  pinMode(led, OUTPUT);     
  pinMode(sensor, INPUT);   
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);       
}

void loop(){
  val = digitalRead(sensor);   
  if (val == HIGH) {           
    digitalWrite(led, HIGH);  
               
    
    if (state == LOW) {
      Serial.println("Motion detected!");
      tone(buzzer, 9000);
      delay(1000);       
      noTone(buzzer);   
      delay(1000);       
      state = HIGH;       
    }
  } 
  else {
      digitalWrite(led, LOW); 
                
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;     
    }
  }
}