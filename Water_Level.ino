const int SensorWaterLevel= A2;

int nilaiSensor = 0;
float hasil = 0;
float tinggiAir;

void setup(){
  Serial.begin(9600);
}

void loop(){
  nilaiSensor = analogRead(SensorWaterLevel);
  hasil = map(nilaiSensor, 300, 1023, 0, 100);
  Serial.print("Nilai Sensor = "); Serial.print(nilaiSensor);
  Serial.print("\t Output = "); Serial.print(hasil);
  tinggiAir = hasil*4/100;
  Serial.print("\t Tinggi Air = ");
  Serial.println(tinggiAir);
  delay(200);
}
