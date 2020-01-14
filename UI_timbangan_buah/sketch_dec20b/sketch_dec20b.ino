void setup() {
Serial.begin(9600);

}

void loop() {
Serial.print(analogRead(A1));
Serial.print("  "+String(analogRead(A2))+"  ");
Serial.println(analogRead(A1));
delay(100);
}
