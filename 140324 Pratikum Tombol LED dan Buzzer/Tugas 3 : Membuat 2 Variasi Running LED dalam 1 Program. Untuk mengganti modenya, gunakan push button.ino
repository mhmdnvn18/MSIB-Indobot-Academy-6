// Lampu LED Berjalan Menggunakan Wemos D1 R1 UNO
// Menyalakan LED dengan Aktif HIGH
// Mode diubah menggunakan Push Button

const int buttonPin = D5; // Pin yang terhubung ke push button
int mode = 1; // Mode awal adalah mode 1

void setup() {
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Mengaktifkan pull-up resistor internal untuk push button
}

void loop() {
  // Mode 1: LED berkedip bergilir
  if (mode == 1) {
    digitalWrite(D4, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D2, LOW);
    delay(100);
    digitalWrite(D4, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D2, LOW);
    delay(100);
    digitalWrite(D4, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D2, HIGH);
    delay(100);
  } 
  // Mode 2: LED berkedip secara bersamaan
  else if (mode == 2) {
    digitalWrite(D4, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D2, HIGH);
    delay(100);
    digitalWrite(D4, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D2, LOW);
    delay(100);
  }

  // Membaca input dari push button untuk mengubah mode
  if (digitalRead(buttonPin) == LOW) { // Jika push button ditekan
    mode++; // Mengganti mode
    if (mode > 2) { // Jika mode melebihi 2, kembali ke mode awal (mode 1)
      mode = 1;
    }
    delay(250); // Delay untuk mencegah bouncing pada push button
  }
}
