int pinLed = 5;
int pinBtn = 4;

void setup() {
  pinMode(pinLed, OUTPUT);
  PinMode(pinBtn, INPUT_PULLUP);
}

void loop()
{
  int statusBtn = digitalRead(pinBtn);
  if(statusBtn == HIGH)
{
  digitalWrite(pinLed, LOW);
} else {
  digitalWrite(pinLed, HIGH);
}}
