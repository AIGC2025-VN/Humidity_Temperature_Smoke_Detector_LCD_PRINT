

#include <LCDI2C_Multilingual_MCD.h>
#include <DHT.h> // Gọi thư viện DHT22
 
const int DHTPIN = 2; //Đọc dữ liệu từ DHT22 ở chân A3 trên mạch Arduino
const int DHTTYPE = DHT22; //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
const int MQ2pin = 0;
DHT dht(DHTPIN, DHTTYPE);
float sensorValue;

LCDI2C_Vietnamese lcd(0x27, 16, 2);   // I2C address: 0x27; Display size: 16x2

void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  Serial.println("Arduino.vn!");
  dht.begin(); // Khởi động cảm biến
  delay(20000);

}

void loop() {
  float h = dht.readHumidity(); //Đọc độ ẩm
  float t = dht.readTemperature(); //Đọc nhiệt độ
  lcd.setCursor(2,0);
  lcd.print("Độ ẩm: ");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Nhiệt độ: ");
  lcd.print(t);
  sensorValue = analogRead(MQ2pin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  if(sensorValue > 0)
  {
    Serial.println(" | Smoke detected!");
  }
  
  Serial.println("");
  delay(1000);
}