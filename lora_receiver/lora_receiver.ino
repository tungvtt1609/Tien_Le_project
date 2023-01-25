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
//  if (!LoRa.begin(433E6)) {
//    Serial.println("Starting LoRa failed!");
//    while (1);
//  }
}

//void loop() {
//  // put your main code here, to run repeatedly:
//     Serial.println("Received packet");
//    if(lora.available()){
//      String input = lora.readString();
//      Serial.print(input); 
//      lcd.print(input); 
//    }
//    for(int i = 0; i < input.length(); i++){
//      if(input.charAt(i) == 'c'){
//        temp = i;  //tìm vị trí chữ c
//      }
//    }
//
//    hum = input;
//    tem = input;
//
//    hum.remove(temp);
//    tem.remove(0, temp + 1);
//    val1 = hum.toInt();
//    val2 = tem.toInt();
//    Serial.print("Humidity: ");
//    Serial.println(val1);
//    Serial.print("Temperature: ");
//    Serial.println(val2);
//    lcd.setCursor(0, 1);
//    lcd.print("Do am: ");
//    lcd.println(val1);
//
//    lcd.print("Nhiet do: ");
//    lcd.println(val2);
//    delay(5000);
  
//}

void loop(){
  while(lora.available()>1) 
  {
//      char incoming = lora.read();
//      Serial.print(input); 
//      lcd.setCursor(0, 1);
//      lcd.print(input);
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
