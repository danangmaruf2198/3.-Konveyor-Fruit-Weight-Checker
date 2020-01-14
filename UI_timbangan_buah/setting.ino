void tombolSetting() {

  if (analogRead(A0) > 950 && analogRead(A0) < 961) {
    Serial.println("S1");
    tombol5 = 1;
  }
  else if (analogRead(A0) > 935 && analogRead(A0) < 946) {
    Serial.println("S2");
    tombol6 = 1;
  }
  else if (analogRead(A0) > 885 && analogRead(A0) < 893) {
    Serial.println("S4");
    tombol4 = 1;
    notombol = 0;
  }
  if (tombol5 != tombol5akhir) {
    if (tombol5 == 1) {
      batas--;
      EEPROM.update(1, batas);
    }
  }
  if (tombol6 != tombol6akhir) {
    if (tombol6 == 1) {
      batas++;
      EEPROM.update(1, batas);
    }
  }
  tombol5akhir = tombol5;
  tombol6akhir = tombol6;
  
  tombol5=0;
  tombol6=0;
  if (batas < 0) {
    batas = 0;
  }
}
void setting() {
  notombol = 2;
  tombolSetting();
  Serial.print(tombol5);
  Serial.print("  ");
  Serial.print(tombol5akhir);
  Serial.print("  ");
  Serial.println(tombol6);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("batas berat=" + String(batas));
  lcd.setCursor(0, 1);
  lcd.print("-  +");
  lcd.setCursor(12, 1);
  lcd.print("back");
}
