void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); // 
}
void loop() {
  if(Serial.available())
  {
    String command = Serial.readStringUntil('n'); 

    if(command == "ON")
    {
      digitalWrite(LED_BUILTIN, HIGH); 
      Serial.println("LED is turned ON");
    }
    else
    if(command == "OFF")
    {
      digitalWrite(LED_BUILTIN, LOW); 
      Serial.println("LED is turned OFF"); 
    }
  }
}
