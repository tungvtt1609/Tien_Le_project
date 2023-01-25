
#include<LiquidCrystal.h>

const int RS = 11;
const int EN = 10;
const int D4 = 9;
const int D5 = 8;
const int D6 = 7;
const int D7 = 6;
LiquidCrystal LCD(8,7,6,5,4,3);

#define LED 13
#define SPK 7

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};
byte heart_h[8] = {
  B00000,
  B00000,
  B01010,
  B10101,
  B10001,
  B01010,
  B00100,  
  B00000
};
byte heart_f[8] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,  
  B00000
};
byte ohm[8] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B01010,  
  B11011
};
byte rect[8] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};
byte arrow_u[8] = {
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,  
  B00100
}; 
byte arrow_d[8] = {  
  B00100,
  B00100,
  B00100,
  B00100,  
  B00100,  
  B11111,
  B01110,
  B00100
}; 
byte diamond[8] = {
  B00000,
  B00100,
  B01010,
  B10001,  
  B01010,
  B00100,
  B00000,
  B00000  
};
void setup() {
  LCD.begin(20, 4);
  LCD.createChar(0, smiley);
  LCD.createChar(1, heart_h);
  LCD.createChar(2, heart_f);
  LCD.createChar(3, ohm);
  LCD.createChar(4, rect);
  LCD.createChar(5, arrow_u);
  LCD.createChar(6, arrow_d);
  LCD.createChar(7, diamond);
}
void loop() {
  for(int i=0;i<8;i++){
    LCD.setCursor(i*2,0);
    LCD.print(char(i));
    delay(200);
  }
  LCD.setCursor(0, 1);
  LCD.print("I love you");
  for(int i=10;i<16;i++){
    LCD.setCursor(i, 1);
    LCD.print(char(2));
    delay(200);
  }
  delay(2000);
  LCD.clear();
  delay(300);
}
