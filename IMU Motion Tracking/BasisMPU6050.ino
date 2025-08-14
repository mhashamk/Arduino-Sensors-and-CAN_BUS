// Demoprogramm für Inertialsensor Cluster MPU6050
// Sensorik in der Mechatronik, Hasham Muhammad
// Connections: Arduino Nano: 5V-5V, GND-GND, A4-SDA ,A5-SCL
// Arduino Micro: 2-SDA, 3-SCL

#include <Wire.h>
#define sensor_address 0x68

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  delay(1000);

  // Powermanagement aufrufen
  SetConfiguration(0x6B, 0x80);
  delay(500);

  // Sleep beenden und Clock von Gyroskopeachse X verwenden
  SetConfiguration(0x6B, 0x03);
  delay(500);

  // Konfiguration aufrufen
  SetConfiguration(0x1A, 0x00);
  SetConfiguration(0x1B, 0x00);
  SetConfiguration(0x1C, 0x00);
  delay(500);
}

void loop()
{
  byte result[14];
  result[0] = 0x3B;
  Wire.beginTransmission(sensor_address);
  Wire.write(result[0]);
  Wire.endTransmission();
  Wire.requestFrom(sensor_address, 14);

  for(int i = 0; i < 14; i++)
  {
    result[i] = Wire.read();
  }

  int acc_X = (((int)result[0]) << 8) | result[1];
  int acc_Y = (((int)result[2]) << 8) | result[3];
  int acc_Z = (((int)result[4]) << 8) | result[5];

  int temp = (((int)result[6]) << 8) | result[7];

  int gyr_X = (((int)result[8]) << 8) | result[9];
  int gyr_Y = (((int)result[10]) << 8) | result[11];
  int gyr_Z = (((int)result[12]) << 8) | result[13];

  Serial.print(gyr_Z); 
  Serial.print("\n");
}

void SetConfiguration(byte reg, byte setting)
{
  Wire.beginTransmission(sensor_address);
  Wire.write(reg);
  Wire.write(setting);
  Wire.endTransmission();
}
