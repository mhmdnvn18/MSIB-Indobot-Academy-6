#include <ESP8266WiFi.h>
#include "DHT.h"

#define DHTTYPE DHT11

const char* ssid = "HOKYA HOKYA";
const char* password = "noconcibaotroshijos";

WiFiServer server(80);

const int DHTPin = D2;
DHT dht(DHTPin, DHTTYPE);

boolean notifyHighTemperature = false;

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

  server.begin();
  Serial.println("Koneksi Server dimulai");

  Serial.print("Alamat IP untuk pengaksesan: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  Serial.println("Koneksi baru");
  while (!client.available()) {
    delay(5);
  }

  if (client) {
    boolean blank_line = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n' && blank_line) {
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

          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();

          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<head>");
          client.println("<script>");
          client.println("function showNotification() {");
          client.println("  alert('Peringatan: Suhu melebihi 30 derajat Celsius!');");
          client.println("}");
          if (notifyHighTemperature) {
            client.println("window.onload = showNotification;");
          }
          client.println("</script>");
          client.println("</head>");
          client.println("<body>");

          client.println("<h1>Wemos D1 - Suhu dan Kelembaban Sensor DHT11</h1>");

          client.print("<h3>Suhu dalam Celcius: ");
          client.print(t);
          client.println("*C</h3>");

          client.print("<h3>Suhu ke dalam Fahrenheit: ");
          client.print(f);
          client.println("*F</h3>");

          client.print("<h3>Kelembaban: ");
          client.print(h);
          client.println("%</h3>");

          client.println("</body></html>");
          break;
        }
        if (c == '\n') {
          blank_line = true;
        }
        else if (c != '\r') {
          blank_line = false;
        }
      }
    }
    delay(5);
  }
}
