#include <LiquidCrystal.h>
#include<EEPROM.h>
#include <Servo.h>
#include  "HX711.h"
HX711 scale(3,2);

Servo katup;
float faktorKalibrasi= -96650;

int inPin = 14;
int val = 0, notombol = 0;
int menu1 = 1; //EEPROM.read(1);
int pilih = 1; //EEPROM.read(2);
int nilai = 0; //EEPROM.read(3);
byte tombol1 = 0, tombolmaju = 0, tombolmundur = 0, tombolservo = 0;
int tombol2 = 0;
int tombol3 = 0;
int tombol4 = 0;
int tombol5 = 0;
int tombol6 = 0;
int ldr=0,kondisi=0;
int tombol1akhir = 1,batas=EEPROM.read(1);
int tombol2akhir = 1;
int tombol3akhir = 1;
int tombol4akhir = 1;
int tombol5akhir = 1;
int tombol6akhir = 1;
float berat, laser,Step;
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  katup.attach(10);
  katup.write(175);
  lcd.begin(16, 2);
  scale.set_scale();
  scale.tare();
  Serial.begin(9600);
}
void loop() {
 while (notombol == 0) {
    Serial.println("www");
    ambiltombol();
    menuawal();
    if ( notombol == 1) {
      break;
    }

  }
  while (notombol == 1) {
    modeManual();
  }
  
  while (notombol == 2) {
    setting();
  }
  while (notombol == 3) {
    programRun();
  }
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print(menu1);
  Serial.print(" ");
  Serial.print(pilih);
  Serial.print(" ");
  Serial.println(notombol);

}
