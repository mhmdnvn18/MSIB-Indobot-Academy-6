int hasil1 = 15 != 10;
int hasil2 = 15 != 15;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Hasil 15 != 10: ");
Serial.println(hasil1);
Serial.print("Hasil 15 != 15: ");
Serial.println(hasil2);
}
