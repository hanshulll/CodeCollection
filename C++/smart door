/*PIN SDA/SS : D2
 *PIN SCK : D5
 *PIN MOSI: D7
 *PIN MISO: D6
 *PIN GND : GND
 *PIN RST : D1
 *PIN 3.3V: 3V
 */
 
//Untuk Komunikasi Serial Blynk
#define BLYNK_PRINT Serial
 
#include <SPI.h> //Menambahkan Library untuk Komunikasi SPI
#include <ESP8266WiFi.h> //Menambahkan Library untuk ESP8266 WiFi
#include <BlynkSimpleEsp8266.h> //Menambahkan Library untuk Blynk
#include <MFRC522.h> //Menambahkan Library untuk RFID
#include <Servo.h>
 
//Definisikan Pin RFID Reader pada Board NodeMCU
#define SS_PIN D2
#define RST_PIN D1
#define Lampu1 D0 //lampu merah
#define Lampu2 D3 //lampu hijau
 
 
char auth[] = "kbOoKOZK_TDqHmMfy8LtO3orrEDQESrt";
char ssid[] = "bayar";
char pass[] = "pakepisanggoreng";
char server[] = "blynk-cloud.com"; //Server Blynk
int port = 8442; //Port yang digunakan untuk terhubung ke Server Blynk
 
MFRC522 rfid(SS_PIN, RST_PIN); //Menggunakan fungsi RFID dari Library
MFRC522::MIFARE_Key key; 
Servo servo;
WidgetLCD lcd(V1); //Definisi pin LCD pada Aplikasi Blynk
 
String strID, userID; //Variabel untuk Menyimpan hasil Pembacaan RFID
 
void setup() 
{
  Serial.begin(19200); //Komunikasi Serial dengan Baudrate 115200
  pinMode(Lampu1, OUTPUT);
  pinMode(Lampu2, OUTPUT);
  servo.attach(2);
  digitalWrite(Lampu1, LOW);
  digitalWrite(Lampu2, LOW);
  Blynk.begin(auth, ssid, pass, server, port);  //Menghubungkan NodeMCU ke Server Blynk menggunakan Wi-Fi
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
}
       
void loop()       // put your main code here, to run repeatedly:
{
  Blynk.run(); //Blynk berjalan
  lcd.clear();
 
  //Digunakan untuk melakukan Deteksi Kartu RFID
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }
  strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
      (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
      String(rfid.uid.uidByte[i], HEX) +
      (i != 3 ? ":" : "");
  }
  strID.toUpperCase();
 
  //Cetak di LCD Aplikasi Blynk apabila RFID Tag terdeteksi
  if (strID != NULL)
  { 
    lcd.print(0, 0, "ID dari RFID :");                                              
    lcd.print(0, 1, strID);
  delay(2000);
    lcd.clear();
    if(strID != userID) 
    {
          lcd.print(0, 0, "ID dari RFID :");                                              
          lcd.print(0, 1, "Akses ditolak");
          digitalWrite(Lampu1, HIGH);
          delay(2000);
          digitalWrite(Lampu1, LOW);
    }  else 
    {
          lcd.print(0, 0, "ID dari RFID :");                                              
          lcd.print(0, 1, "Akses diizinkan");
          digitalWrite(Lampu2, HIGH);
          servo.write(180);
          delay(2000);
          servo.write(60);
          digitalWrite(Lampu2, LOW);
    }
    userID = strID;
  }
  else{
    lcd.print(0, 0, "ID dari RFID :");                                              
    lcd.print(0, 1, "Tidak ditemukan");
    delay(2000);
  }
}   
