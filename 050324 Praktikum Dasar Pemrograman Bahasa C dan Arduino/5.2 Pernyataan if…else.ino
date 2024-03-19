int A = 5 ;
int B = 9 ;
int C;
void setup () {
  Serial.begin(9600);
}

void loop () {
/* cek kondisi boolean */
if (A > B) /* jalankan pernyataan berikut ini, jika kondisi benar maka output yang akan keluar tertuliskan 5, jika salah maka output yang akan keluar tertuliskan "C:4",*/ 
{
Serial.println(A);
} else {
Serial.print("C :");
Serial.println(C=B-A);
delay(1000);
}
