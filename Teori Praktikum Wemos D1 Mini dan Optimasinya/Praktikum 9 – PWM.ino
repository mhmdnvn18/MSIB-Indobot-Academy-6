// Define the LED pin
const int led_pin = 9;

void setup() {
  // Declaring LED pin as output
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // Fade in
  for (int i = 0; i < 255; i++) {
    analogWrite(led_pin, i);
    delay(5);
  }

  // Fade out
  for (int i = 255; i > 0; i--) {
    analogWrite(led_pin, i);
    delay(5);
  }
}
