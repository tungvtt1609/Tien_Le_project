#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <LoRa.h>
#include "DHT.h"
#include <SPI.h>

#define TX 9
#define RX 10
const int DHTPIN = 8;
const int DHTTYPE = DHT22;
int counter = 0;
int led = 13;
int spk = 7;

const int RS = 12;
const int EN = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial lora(TX, RX);  //TX, RX
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup(){
  Serial.begin(115200);
  lora.begin(115200);
  lcd.clear();
  lcd.begin(16, 2);
  dht.begin();
  pinMode(led, OUTPUT);
  pinMode(spk, OUTPUT);
  
  while(!Serial);
  Serial.println("Lora Sender");
}

void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(t > 40){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(spk, HIGH);
    delay(1000);    
  }
  else
  {
    digitalWrite(led, LOW);
    delay(1000);
    digitalWrite(spk, LOW);
    delay(1000);  
  }
  Serial.print("Sending packet: ");
  Serial.println(counter);

  lora.print("Do am: ");
  lora.println(h);
  lora.print("c");
  lora.print("Nhiet do: ");
  lora.println(t);

  lcd.setCursor(0, 0);
  lcd.print("Do am: ");
  lcd.println(h);
  lcd.setCursor(0, 1);
  lcd.print("Nhiet do: ");
  lcd.println(t);
  
  Serial.print("Do am: ");
  Serial.println(h);
  Serial.print("Nhiet do: ");
  Serial.println(t);
  
  counter++;
  delay(2000);
}  
