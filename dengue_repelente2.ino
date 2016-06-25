int ledPin = 13;
int piezoPin = 6;
int frequency = 31000; // 31kHz - contra mosquito dengue!

void setup(){
  pinMode(piezoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  
    digitalWrite(ledPin, HIGH);
    tone(piezoPin, frequency, 1000);
    Serial.print("Dengue Scare On");
 
}
  

