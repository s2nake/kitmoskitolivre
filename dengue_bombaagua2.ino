
/*
 Dengue control
 */

// Bibliotecas
#include <Stepper.h>
#include <DS1307.h>
// #include <SD.h>
#include <Thermistor.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// SD Card
// const int chipSelect = 17;
// File gFile;
 
// RTC DS1307 
DS1307 rtc(A2, A1); 

// Water Plump
const int stepsPerRevolution = 20;  
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// Sensor Temp
Thermistor temp(0);

// LCD Display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Array simbolo grau
byte termometru[8] = //icon for termometer
{
    B00100,
    B01010,
    B01010,
    B01110,
    B01110,
    B11111,
    B11111,
    B01110
};

void setup() {
  
  // Velocidade do Motor
  myStepper.setSpeed(750);
  
      // Iniciar LCD Display
      lcd.begin();
      lcd.backlight();
      lcd.print("Dengue Control");
      delay(1000);
      lcd.clear();
      lcd.createChar(1,termometru);
      
      // Iniciar RTC
      rtc.halt(false);
      rtc.setDOW(MONDAY);      // Define o dia da semana
      rtc.setTime(17, 30, 0);     // Define o horario
      rtc.setDate(20, 06, 2016);   // Define o dia, mes e ano
      rtc.setSQWRate(SQW_RATE_1);
      rtc.enableSQW(true);
  
  // Inigial Serial
 // Serial.begin(9600);
  
 /*
  // Iniciar SD Card
  Serial.print("Iniciando SD card... ");
 
  pinMode(SS, OUTPUT);
  
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("SD nao encontrado... Tentar novamente");
    while (1) ;
  }
    gFile = SD.open("dados.txt", FILE_WRITE);
  if (! gFile) 
  {
    Serial.println("Erro ao abrir dados.txt");
     while (1) ;
  }
    Serial.println("Data logging iniciado");
    
    */
  
}

void loop() {
      
      // Motor - step one revolution in one direction:
      myStepper.step(stepsPerRevolution);
      
      // Temp
      int temperature = temp.getTemp();
      
      // LCD Display
      lcd.setCursor(0, 0);   // set cursor to second row, first column
      lcd.print(rtc.getDateStr(FORMAT_SHORT));
      lcd.print(" ");
      lcd.print(rtc.getTimeStr());
      lcd.print(" ");
      lcd.setCursor(0, 1);   // set cursor to second row, first column
      lcd.print(temperature);
      lcd.print((char)223); //degree sign
      lcd.print("C");
        
     /*
     // Mostra as informações no Serial Monitor
      Serial.print("Day: ");
      Serial.print(rtc.getDateStr(FORMAT_SHORT));
      Serial.print(" ");
      
     //  gFile.print(rtc.getDateStr(FORMAT_SHORT));  // data
      
      Serial.print("Hour: ");
      Serial.print(rtc.getTimeStr());
      Serial.print(" ");
      
    //  gFile.print(rtc.getTimeStr()); // hora
       
      Serial.print("Temp: ");
      Serial.print(temperature);
      Serial.println(" *C");
      
      // gFile.print(temperature); // som ambiente
    
    //  gFile.flush();
    */
   
}

