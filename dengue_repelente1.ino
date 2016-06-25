int buttonPin = 2;
int buttonState = 0;  
int ledPin = 13;
int piezoPin = 9;
int frequency = 31000; // 31kHz - contra mosquito dengue!

void setup(){
  pinMode(piezoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
}

void loop(){
  
  buttonState = digitalRead(buttonPin);
  
    if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone(piezoPin, frequency, 1000);
    Serial.print(frequency);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
  

