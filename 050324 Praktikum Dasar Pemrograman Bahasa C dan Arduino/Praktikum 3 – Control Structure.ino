/* Definisi Variabel Global */
int a = 5;
int b = 9 ;
int c;
void setup () {
  Serial.begin(9600);
}


void loop () {
/* periksa kondisi boolean */
if (a > b) /* jika kondisi benar maka eksekusi pernyataan berikut ini, output berupa "5" */
Serial.println(a);
/* periksa kondisi boolean */
if ( ( a < b ) && ( b != 0 )) /* jika kondisi benar maka eksekusi pernyataan berikut ini, output berupa "C:14" */ {
Serial.print("C :");
Serial.println(c=a+b);
delay (1000);
}
}
