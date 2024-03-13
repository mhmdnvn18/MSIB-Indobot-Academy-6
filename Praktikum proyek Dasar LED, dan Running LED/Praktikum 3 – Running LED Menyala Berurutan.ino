// Program variasi LED oleh Indobot.co.id
int LED[] = {D0, D1, D2, D3};

void setup() {
  // program ini berfungsi sebagai inisialisasi LED pin menggunakan pin 0, 1, 2, dan 3
  for (int i = 0; i <= 3; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  // program untuk menyalakan LED secara berurutan
  for (int i = 0; i <= 3; i++) {
    digitalWrite(LED[i], HIGH);
    delay(1000);
  }
  // ketika semua LED sudah menyala, maka 1 detik kemudian, semua LED dimatikan agar dapat berulang-ulang
  for (int i = 0; i <= 3; i++) {
    digitalWrite(LED[i], LOW);
  }
  delay(1000); // tambahkan delay 1 detik agar setelah semua LED menyala, ada jeda sebelum kembali ke awal
}
