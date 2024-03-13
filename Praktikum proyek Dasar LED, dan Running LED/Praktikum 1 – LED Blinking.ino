// Menyalakan LED Menggunakan Wemos D1 Mini
// Menyalakan LED dengan Aktif HIGH

void setup() {
  pinMode(D4, OUTPUT); // menjadikan PIN 4 sebagai OUTPUT
}

void loop() {
  digitalWrite(D4, HIGH); // Menyalakan PIN 4 (HIGH = Memberi tegangan pada PIN 4)
  delay(1000); // Pause selama 1 detik

  digitalWrite(D4, LOW); // Mematikan PIN 4 (LOW = Tidak Memberi tegangan pada PIN 4)
  delay(1000); // Pause selama 1 detik
}
