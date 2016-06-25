	
// Programa : Controlando o servo com 3 chaves
// Autor: Arduino e Cia

#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(9);   
  pinMode(myservo, OUTPUT);      
} 

void loop() 
{ 
  digitalWrite(myservo, HIGH);  
}
