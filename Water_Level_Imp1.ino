/*
Wiring :
 Sensor ========> Arduino
 + / VCC    =>     5V
 - / Gnd    =>     Gnd
 S / Signal =>     A0
*/

#define pinSensor A0  //mendefinisikan pin A0 sebagai pin yang berhubungan dengan sensor
int sensorValue = 0; //variable untuk menampung nilai baca dari sensor dalam bentuk integer
float tinggiAir = 0; //variabel untuk menampung ketinggian air
float sensorVoltage = 0; //untuk menampung nilai ketinggian air

int nilaiMax = 1023; // nilai "sensorValue" saat sensor terendam penuh kedalam air, bisa dirubah sesuai sensor dan jenis air yang anda pakai
float panjangSensor = 4.0 ; // 4.0 cm, bisa dirubah

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // mengatur boudrate komunikasi serial antara arduino dengan PC
  Serial.println("Pembacaan Ketinggian Air");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(pinSensor); // membaca tengan dari sensor dalam bentuk integer
  tinggiAir = sensorValue*panjangSensor/nilaiMax;
  sensorVoltage = sensorValue*5.0/1023;
  Serial.print("Value = ");
  Serial.print(sensorValue);
  Serial.print("\tVoltage = ");
  Serial.print(sensorVoltage);
  Serial.print("\tTinggi = ");
  Serial.println(tinggiAir);
  delay(300);
}
