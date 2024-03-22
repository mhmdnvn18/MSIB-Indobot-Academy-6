#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//---------------------------------------------------------------
//Our HTML webpage contents in program memory
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
<a href="ledBlink" class="button">LED Blink</a><br>
<p>Website ini digunakan untuk melakukan kendali LED, klik "LED ON" untuk menyalakan lampu<br>klik "LED OFF" untuk matikan Lampu, klik "LED BLINK" untuk mengedipkan lampu</p>
<hr>
<a href="https://indobot.co.id">Indobot Academy</a>
</center>

</body>
</html>
)=====";

//On board LED Connected to GPIO2
#define LED D2

//SSID and Password of your WiFi router
const char* ssid = "HOKYA HOKYA";
const char* password = "noconcibaotroshijos";

ESP8266WebServer server(80); //Server on port 80

void handleRoot() {
  Serial.println("You called root page");
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s); //Send web page
}

void handleLEDon() {
  Serial.println("LED on page");
  digitalWrite(LED,HIGH); //LED is connected in reverse
  server.send(200, "text/html", "LED is ON"); //Send ADC value only to client ajax request
}

void handleLEDoff() {
  Serial.println("LED off page");
  digitalWrite(LED,LOW); //LED off
  server.send(200, "text/html", "LED is OFF"); //Send ADC value only to client ajax request
}

void handleLEDblink() {
  Serial.println("LED blink page");
  
  // Loop untuk mengedipkan LED
  for (int i = 0; i < 99; i++) {
    digitalWrite(LED, HIGH); // Hidupkan LED
    delay(200); // Tunda selama 200 ms
    digitalWrite(LED, LOW); // Matikan LED
    delay(200); // Tunda selama 200 ms
  }
  
  server.send(200, "text/html", "LED is BLINK"); // Kirim respons ke klien
}

void setup(void){
  Serial.begin(115200);
  WiFi.begin(ssid, password); //Connect to your WiFi router
  Serial.println("");
  pinMode(LED,OUTPUT); //Onboard LED port Direction output
  digitalWrite(LED,HIGH); //Power on LED state off

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); //IP address assigned to your ESP

  server.on("/", handleRoot);
  server.on("/ledOn", handleLEDon);
  server.on("/ledOff", handleLEDoff);
  server.on("/ledBlink", handleLEDblink);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
