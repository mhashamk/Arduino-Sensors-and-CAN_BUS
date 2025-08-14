const int AirValue = 576; you need to replace this value with Value_1
const int AirValue = 561; Calculated
const int WaterValue = 331; you need to replace this value with Value_2
const int WaterValue = 364; Calculated
int soilMoistureValue = 0;
int soilmoisturepercent=0;
float voltage=0.0;
void setup() {
Serial.begin(9600);  open serial port, set the baud rate to 9600 bps
}
void loop() {
soilMoistureValue = analogRead(A0); put Sensor insert into soil
voltage=analogRead(A0)(5.01023.0);
Serial.println(soilMoistureValue);
Serial.println(voltage);
soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100); map command
if(soilmoisturepercent = 100)
{
Serial.println(100 %);
}
else if(soilmoisturepercent =0)
{
Serial.println(0 %);
}
else if(soilmoisturepercent 0 && soilmoisturepercent  100)
{
Serial.print(soilmoisturepercent);
Serial.println(%);
}
delay(250);
}