int x = 7;
int x = 7;
int y = 3;
int z = x % y;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(z);

}
