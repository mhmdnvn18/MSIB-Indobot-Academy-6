#include <ESP8266WiFi.h>
#include "DHT.h"
#include <ESP8266WebServer.h>

#define DHTTYPE DHT11

const char* ssid = "HOKYA HOKYA";
const char* password = "noconcibaotroshijos";

const int DHTPin = D2;
DHT dht(DHTPin, DHTTYPE);

boolean notifyHighTemperature = false;

const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<style>
h1 {
  color : blue;
  font-family : Montserrat;
  }
a {
  font: bold 11px Montserrat;
  text-decoration: none;
  background-color: orange;
  color: white;
  padding: 2px 6px 2px 6px;
  border-top: 1px solid #CCCCCC;
  border-right: 1px solid #333333;
  border-bottom: 1px solid #333333;
  border-left: 1px solid #CCCCCC;
}
p{font-family : Sans-serif;
  }

</style>
<center>
<h1>Kontrol LED Indobot Academy</h1><br>
<a href="ledOn" class="button">LED ON</a><br>
<a href="ledOff" class="button">LED OFF</a><br>
<p>Website ini digunakan untuk melakukan kendali LED, klik "LED ON" untuk menyalakan lampu<br>klik "LED OFF" untuk matikan Lampu</p>
{humidity}
{temperature}
<hr>
<a href="https://indobot.co.id">Indobot Academy</a>
</center>

</body>
</html>
)=====";

#define LED D2

ESP8266WebServer server(80);

void handleLEDon(); // Deklarasi fungsi handleLEDon
void handleLEDoff(); // Deklarasi fungsi handleLEDoff
void handleRoot(); // Deklarasi fungsi handleRoot

void setup() {
  Serial.begin(9600);
  delay(20);
  dht.begin();

  Serial.println();
  Serial.print("Menghubungkan ke jaringan... ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Jaringan WiFi terkoneksi");

  server.on("/", handleRoot);
  server.on("/ledOn", handleLEDon);
  server.on("/ledOff", handleLEDoff);

  server.begin();

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH); //Power on LED state off

  Serial.print("Alamat IP untuk pengaksesan: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  server.handleClient();

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
  }
  else {
    Serial.print("Kelembaban : ");
    Serial.print(h);
    Serial.println("%");

    Serial.print("Suhu : ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.println(f);

    if (t > 30) {
      notifyHighTemperature = true;
    }
  }

  delay(5000); // Delay 5 detik sebelum membaca sensor lagi
}

void handleLEDon() {
  Serial.println("LED on page");
  digitalWrite(LED, LOW); //LED on
}

void handleLEDoff() {
  Serial.println("LED off page");
  digitalWrite(LED, HIGH); //LED off
}

void handleRoot() {
  Serial.println("You called root page");
  String s = MAIN_page; // Read HTML contents

  // Mengambil nilai kelembaban dan suhu dari sensor DHT
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  // Membuat string HTML dengan nilai kelembaban dan suhu
  String humidityString = "<p>Kelembaban: " + String(h) + " %</p>";
  String temperatureString = "<p>Suhu: " + String(t) + " &#8451; (" + String(f) + " &#8457;)</p>";

  // Mengganti placeholder di halaman web dengan nilai kelembaban dan suhu
  s.replace("{humidity}", humidityString);
  s.replace("{temperature}", temperatureString);

  server.send(200, "text/html", s); // Mengirim halaman web yang diperbarui
}
