// program variasi LED oleh Indobot.co.id
int LED[] = {D0, D1, D2, D3};

void setup() {
  // program ini berfungsi sebagai inisialisasi LED pin menggunakan pin 0, 1, 2, dan 3
  for (int i = 0; i < 4; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  // program untuk menyalakan LED bergantian dari kanan ke kiri
  for (int i = 0; i < 4; i++) {
    digitalWrite(LED[i], HIGH);
    delay(200);
    digitalWrite(LED[i], LOW);
    delay(50); // tambahkan delay agar ada jeda antara setiap LED
  }

  // program untuk menyalakan LED bergantian dari kiri ke kanan
  for (int i = 3; i >= 0; i--) {
    digitalWrite(LED[i], HIGH);
    delay(200);
    digitalWrite(LED[i], LOW);
    delay(
