int ledPin = D2; // Kaki positif LED terhubung ke pin D2 Wemos

void setup()
{
pinMode(ledPin, OUTPUT); // mengatur digital pin sebagai Output
}

void loop()
{
digitalWrite(ledPin, HIGH); // LED menyala
delay(1000); // Jeda selama 1 detik
digitalWrite(ledPin, LOW); // LED mati
delay(1000); // Jeda selama 1 detik
}
