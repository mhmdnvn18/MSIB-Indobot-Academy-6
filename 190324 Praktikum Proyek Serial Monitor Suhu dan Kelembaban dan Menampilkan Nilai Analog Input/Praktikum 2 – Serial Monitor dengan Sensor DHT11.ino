#include "DHT.h" // Inisiasi library DHT11
#define DHTPIN D2 // Buat variabel DHTPIN, mengarah pada pin D2
#define DHTTYPE DHT11 // Tentukan tipe DHT menjadi DHT11
DHT dht(DHTPIN, DHTTYPE); // Buat objek dht

void setup() {
Serial.begin(115200); // Buka komunikasi serial pada baudrate 115200
dht.begin(); // Inisiasi objek dht
}

void loop() {
float hum = dht.readHumidity(); // Baca kelembapan
float temp = dht.readTemperature(); // Baca temperatur
if (isnan(hum) || isnan(temp)) { // Cek jika sensor error
Serial.println("Gagal Membaca DHT sensor!");
return;
}

Serial.println("Temperature: " + (String)temp + " *C"); // Print temperatur (*C)
Serial.println("Humidity: " + (String)hum + " %"); // Print kelembapan 
delay(1000);
}
