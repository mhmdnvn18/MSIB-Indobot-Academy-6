#include <LiquidCrystal.h> //mengincludekan library LCD

//untuk urutannya RS, E, 4, 5, 6, 7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //pin yang disambungkan antara arduino dengan LCD
void setup()
{
//prosedur pemanggilan fungsi LCD
lcd.begin(16, 2);//16 = Baris, 2 = kolom
}

void loop() {
lcd.setCursor(00,00); //set pada baris 1 dan kolom 1
lcd.print("INDOBOT ACADEMY"); //menuliskan "INDOBOTACACEMY"
lcd.setCursor(00,1);//set pada baris 2 dan kolom 1
lcd.print("BELAJAR LCD");
delay(3000); //waktu tunda 3 detik
lcd.clear();

//Tampilan kedua
lcd.setCursor(00,00); //set pada baris 1 dan kolom 1
lcd.print("BELAJAR ARDUINO"); //menuliskan "Hallo Dunia"
lcd.setCursor(00,1); //set pada baris 2 dan kolom 1
lcd.print("SERU SEKALI!");
delay(3000); //waktu tunda 3 detik
lcd.clear();
}
