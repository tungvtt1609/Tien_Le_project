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
float hum_value = 0.0;
float temp_value = 0.0;

String inString = "";
String MyMessage = "";

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
    int packetSize = lora.parsePacket();
    if(packetSize){
        while(lora.available()){
            int inChar = lora.read();
            inString += (char)inChar;
            MyMessage = inString;
        }
    }

    String hum = getvalue(inString, ',', 0);
    String temp = getvalue(inString, ',', 1);

    hum_value = hum.toFloat();
    temp_value = temp.toFloat();

    Serial.print("Do am: ");
    Serial.println(hum_value);
    Serial.print(" Nhiet do: ");
    Serial.println(temp_value);

    if((temp_value >= 40) || (hum_value >= 90)){
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(spk, HIGH);
        delay(1000); 
    }
    else{
        digitalWrite(led, LOW);
        delay(1000);
        digitalWrite(spk, LOW);
        delay(1000); 
    }

    inString = "";
 
}

String getvalue(String data, char separator, int index){
    int found = 0;
    int strIndex[] = {0, -1};
    int maxIndex = data.length() - 1;
    for(int i = 0; i <= maxIndex && found <= index; i++){
        if(data.CharAt(i) == separator || i == maxIndex){
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}