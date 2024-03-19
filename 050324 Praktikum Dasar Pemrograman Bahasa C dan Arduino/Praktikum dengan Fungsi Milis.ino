int outputLED = 13;
long durasiLED = 0;
long jedaLED = 500;
int statusLED = LOW;
void setup()
{
  pinMode(outputLED, OUTPUT);
}

void loop()
{
  if (millis()-durasiLED>jedaLED_
  {durasiLED = millis();
if (statusLED == LOW)
{
statusLED = HIGH;
}
else
}
statusLED = LOW;
}
digitalWrite(13,statusLED);
}
}
