#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <LoRa.h>

#define TX 8
#define RX 9

const int RS = 12;
const int EN = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;

int led = 13;
int spk = 7;

//String input ="";
String hum, tem;
byte temp;
int val1, val2;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
SoftwareSerial lora(TX, RX);  //TX, RX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lora.begin(115200);
  lcd.clear();
  lcd.begin(16, 2);
  while (!Serial);
  Serial.println("LoRa Receiver");


void loop(){
  while(lora.available()>1) 
  {
    char incoming = (char)lora.read();
    if (incoming == 'c')
    {
      lcd.setCursor(0, 1);
    }
    else
    {
      lcd.print(incoming);
      Serial.print(incoming);
    }
  }
}
