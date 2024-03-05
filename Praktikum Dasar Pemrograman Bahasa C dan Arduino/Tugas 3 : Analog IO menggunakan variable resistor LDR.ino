int pinLed1 = 11; // pin PWM (Pulse Width Modulation)
int pinLDR  = A0;  // pin A0 terhubung ke sensor LDR

void setup() 
{
  Serial.begin(9600);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLDR, INPUT);
}

void loop() 
{
  int nilaiLDR = analogRead(pinLDR);
  Serial.print("Nilai LDR: ");
  Serial.println(nilaiLDR);

  // Pemetaan nilai LDR ke kecerahan LED (rentang PWM adalah 0 hingga 255)
  int kecerahan = map(nilaiLDR, 0, 1023, 0, 255);

  analogWrite(pinLed1, kecerahan);

  delay(100);
}
