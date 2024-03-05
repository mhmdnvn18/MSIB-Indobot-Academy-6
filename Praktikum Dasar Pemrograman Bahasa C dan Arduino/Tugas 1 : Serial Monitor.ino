String Nama_saya  = "Muhammad Novian";
String Kelas_saya = "LDR";
/*Pemberian tipe data dan pengisian variabel*/

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  Serial.print("Nama Lengkap: ");
  Serial.println(Nama_saya);
  delay(1000);
  Serial.print("Kelas       : ");
  Serial.println(Kelas_saya);
  delay(1000);
}
