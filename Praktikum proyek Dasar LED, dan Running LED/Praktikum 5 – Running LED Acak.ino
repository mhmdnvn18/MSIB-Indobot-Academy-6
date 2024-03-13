// program variasi LED oleh Indobot.co.id
int LED[] = {D0, D1, D2, D3};

void setup() {
  // inisialisasi LED pin 0, 1, 2, dan 3 sebagai output
  for (int i = 0; i < 4; i++) {
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  // menambahkan nilai untuk array LED[]
  int pin;
  // memilih angka acak sesuai array
  pin = random(4);
  // program untuk menyalakan LED secara acak
  digitalWrite(LED[pin], HIGH);
  delay(1000); // tambahkan delay untuk membuat LED tetap menyala setelah dipilih secara acak
  digitalWrite(LED[pin], LOW);
}
