void programRun() {
  ldr = 0;
  digitalWrite(9, HIGH);

  if (analogRead(A1) >= 600) {
    ldr = 1;
  }
  else if (analogRead(A3) >= 500) {
    ldr = 2;
  }
  if (ldr == 1) {
    kondisi = 1;
  }
  else if (ldr == 2) {
    kondisi = 2;
  }
  if (kondisi == 1) {
    digitalWrite(9, LOW);
  }
  else if (kondisi == 2) {
    digitalWrite(9, HIGH);
    katup.write(20);
    scale.set_scale(faktorKalibrasi); //Adjust to this calibration facto
    berat = scale.get_units() * 100;
    if (berat >= batas) {
      kondisi = 3;
    }
  }
  else if (kondisi == 3) {
    katup.write(175);
    delay(500);
    digitalWrite(9, LOW);
    delay(2000);
    digitalWrite(9, HIGH);
    kondisi = 0;
  }
  else {
    kondisi = 0;
  }

  Serial.print(berat);
  Serial.print("  ");
  Serial.print(batas);
  Serial.print("  ");
  Serial.print(kondisi);
  Serial.print("  ");
  Serial.print(analogRead(A1));
  Serial.print("  ");
  Serial.println(analogRead(A3));
  notombol = 3;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("berat=" + String(berat));
  lcd.setCursor(0, 1);
  lcd.print("proses=" + String(kondisi));
  lcd.setCursor(12, 1);
  lcd.print("back");
  if (analogRead(A0) > 885 && analogRead(A0) < 893) {
    Serial.println("S4");
    tombol4 = 1;
    notombol = 0;
  }
}
