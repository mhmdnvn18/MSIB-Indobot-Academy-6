void setup() {
/*Semua program di void setup()
hanya akan di jalankan sekali saja*/

Serial.begin(9600);
Serial.println("Welcome to my world");
}

void loop() {
/*Semua program yang ada di void loop()
akan di jalankan berkali-kali secara
berkala*/

Serial.println("Hello World !!");
delay(1000);
}
