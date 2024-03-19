unsigned int tinggi = 169; 

void setup(){
Serial.begin(9600);
}
void loop(){
Serial.print("tinggi badan ");
Serial.println(tinggi);
delay(1000);
}
