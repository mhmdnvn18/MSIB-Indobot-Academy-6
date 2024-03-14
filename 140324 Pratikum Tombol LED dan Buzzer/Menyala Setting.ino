// Lampu LED Berjalan Menggunakan Wemos D1 R1 UNO
// Menyalakan LED dengan Aktif HIGH

void setup() 
{
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);
}
void loop() 
{
    digitalWrite(D4, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D1, LOW);
    delay(1000);
    digitalWrite(D4, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D1, HIGH);
    delay(1000);
  }
