
int led = 9;	// motor is connected to digital pin 5
void setup()	
{	
pinMode(led, HIGH);	
}	
void loop()	// run over and over again
{	
digitalWrite(led, HIGH);	// turn the motor on
delay(1000);	// delay for 1 second
digitalWrite(led, LOW);	// turn the motor off
delay(1000);	// delay for 1 second
}
