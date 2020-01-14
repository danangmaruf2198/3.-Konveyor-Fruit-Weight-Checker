void ambiltombol() {
  notombol=0;
  
  if (analogRead(A0) > 950 && analogRead(A0) < 961) {
    Serial.println("1");
    tombol1 = 1;
    tombol2 = 0;
    tombol3 = 0;
    tombol4 = 0;
  }
  else if (analogRead(A0) > 935 && analogRead(A0) < 946) {
    Serial.println("2");
    tombol1 = 0;
    tombol2 = 1;
    tombol3 = 0;
    tombol4 = 0;
  }
  else if (analogRead(A0) > 835 && analogRead(A0) < 843) {
    Serial.println("3");
    tombol1 = 0;
    tombol2 = 0;
    tombol3 = 1;
    tombol4 = 0;
  }
  else if (analogRead(A0) > 885 && analogRead(A0) < 893) {
    Serial.println("4");
    tombol1 = 0;
    tombol2 = 0;
    tombol3 = 0;
    tombol4 = 1;
  }
  else {
    tombol1 = 0;
    tombol2 = 0;
    tombol3 = 0;
    tombol4 = 0;
  }}
  void menuawal() {
  tombolManual();
    if (tombol1 != tombol1akhir) {
      if (tombol1 == HIGH) {
        menu1++;
      }
    }
    if (tombol2 != tombol2akhir) {
      if (tombol2 == HIGH) {
        menu1--;
      }
    }
    if (tombol3 != tombol3akhir) {
      if (tombol3 == HIGH) {
        pilih++;
      }
    }
    if (tombol4 != tombol4akhir) {
      if (tombol4 == HIGH) {
        pilih--;
      }
    }
    tombol1akhir = tombol1;
    tombol2akhir = tombol2;
    tombol3akhir = tombol3;
    tombol4akhir = tombol4;
    tombol1=0;
    tombol2=0;
    tombol3=0;
    tombol4=0;
    if (menu1 > 3) {
      menu1 = 1;
    }
    if (menu1 < 1) {
      menu1 = 3;
    }
    if (pilih > 3) {
      pilih = 3;
    }
    if (pilih < 1) {
      pilih = 1;
    }
  
    if (pilih == 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("DITIMBANG DULU");
      lcd.setCursor(0, 1);
      lcd.print("MENU tekan");
      lcd.setCursor(10, 1);
      lcd.print("OK");
    }
    if (menu1 == 1 && pilih == 2) {
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("RUN");
      lcd.setCursor(0, 1);
      lcd.print("<<  >>");
      lcd.setCursor(9, 1);
      lcd.print("OK BACK");
    }
    else if (menu1 == 2 && pilih == 2) {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("setting");
      lcd.setCursor(0, 1);
      lcd.print("<<  >>");
      lcd.setCursor(9, 1);
      lcd.print("OK BACK");
    }
    else if (menu1 == 3 && pilih == 2) {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("manual");
      lcd.setCursor(0, 1);
      lcd.print("<<  >>");
      lcd.setCursor(9, 1);
      lcd.print("OK BACK");
    
    }
     else if (menu1 == 1 && pilih == 3) {
      programRun();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("berat"+String(berat));
      lcd.setCursor(0, 1);
      lcd.print(laser);
      lcd.setCursor(12, 1);
      lcd.print("back");
    }
    else if (menu1 == 2 && pilih == 3) {
      setting();
    } 
    else if (menu1 == 3 && pilih == 3) {
      notombol=1;
      modeManual();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("use btn, W="+String(berat));
      lcd.setCursor(0, 1);
      lcd.print("<<");
      lcd.setCursor(4, 1);
      lcd.print(">>");
      lcd.setCursor(6, 1);
      lcd.print("katup");
      lcd.setCursor(12, 1);
      lcd.print("back");
    }
  }
  
