const int delay_value=1000;

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
digitalWrite(LED_BUILTIN, HIGH);
delay(delay_value); // wait for a second
digitalWrite(LED_BUILTIN, LOW);
delay(delay_value); // wait for a second
}
