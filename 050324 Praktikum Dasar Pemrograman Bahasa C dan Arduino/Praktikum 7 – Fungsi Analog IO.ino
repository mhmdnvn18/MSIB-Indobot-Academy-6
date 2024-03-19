int led = 5;
int pinPot = 0;
int potVal = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  potVal = analogRead(pinPot);
  potVal = map(potVal, 0, 1023, 0, 255);
  analogWrite(led, potVal);
}
