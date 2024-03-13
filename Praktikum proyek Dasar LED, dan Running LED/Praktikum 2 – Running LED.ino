// Lampu LED Berjalan Menggunakan Wemos D1 R1 UNO
// Menyalakan LED dengan Aktif HIGH

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  // menjadikan PIN 0, 1, 2, dan 3 sebagai OUTPUT
}

void loop() {
  // menyala secara bergilir
  digitalWrite(D0, HIGH);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  delay(1000);
  
  digitalWrite(D0, LOW);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  delay(1000);
  
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  delay(1000);
  
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  delay(1000);
}
