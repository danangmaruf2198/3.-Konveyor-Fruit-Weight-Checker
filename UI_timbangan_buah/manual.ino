void tombolManual() {

  if (analogRead(A0) > 950 && analogRead(A0) < 961) {
    Serial.println("1");
    tombolmaju = 1;
  }
  else if (analogRead(A0) > 935 && analogRead(A0) < 946) {
    Serial.println("2");
    tombolmundur = 1;
    }
  else if (analogRead(A0) > 835 && analogRead(A0) < 843) {
    Serial.println("3");
    tombolservo = 1;
    }
  else if (analogRead(A0) > 885 && analogRead(A0) < 893) {
    Serial.println("4");
    tombol4 = 1;
    notombol=0;
  }
  else {
    tombolmaju = 0;
    tombolmundur = 0;
    tombolservo = 0;
    tombol4 = 0;
  }}
void modeManual() {
  tombolManual();
  katup.write(150);
    Serial.print("=============================");
    Serial.print("  ");
    Serial.print(tombolmundur);
    Serial.print("  ");
    Serial.println(tombolservo);
    
    
  if (tombolmaju == 1) {
    Serial.println("relay1");
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  else if (tombolmundur == 1) {
    Serial.println("relay2");
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  else if (tombolservo == 1) {
    Serial.println("servo");
    digitalWrite(8, 1);
    digitalWrite(9, 1);
    tombolservo=0;
  }
  else {
    digitalWrite(8, 1);
    digitalWrite(9, 1);
    katup.write(0);
  }
  if (analogRead(A0) > 885 && analogRead(A0) < 893) {
    Serial.println("4");
    tombol1 = 0;
    tombol2 = 0;
    tombol3 = 0;
    tombol4 = 1;}
}
  
