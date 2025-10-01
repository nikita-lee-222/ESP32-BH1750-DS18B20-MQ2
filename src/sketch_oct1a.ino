#include <Wire.h>
#include <BH1750.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define SDA_PIN 21      // I2C data for BH1750
#define SCL_PIN 22      // I2C clock for BH1750
#define DS18B20_PIN 4   // 1-Wire pin for DS18B20
#define MQ2_PIN 34      // Analog input pin for MQ-2

// I2C address 0x23 (ADDR = GND)
BH1750 lightSensor(0x23); 
OneWire oneWire(DS18B20_PIN);
DallasTemperature tempSensor(&oneWire);

void setup() {
  Serial.begin(115200);

  // Initialize I2C
  Wire.begin(SDA_PIN, SCL_PIN);

  // Initialize BH1750
  if (lightSensor.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println("BH1750 status: OK");
  } else {
    Serial.println("BH1750 status: FAIL");
  }

  // Initialize DS18B20
  tempSensor.begin();

  Serial.println("Sensors setup complete!");
}

void loop() {
  float lux = lightSensor.readLightLevel();
  if (lux < 0) lux = 0; // Just an error protection

  tempSensor.requestTemperatures(); 
  float tempC = tempSensor.getTempCByIndex(0);

  int mq2Value = analogRead(MQ2_PIN); 

  Serial.print("Lux: ");
  Serial.print(lux);
  Serial.print("\tTemp: ");
  Serial.print(tempC);
  Serial.print("°C\tMQ-2: ");
  Serial.println(mq2Value);

  delay(5000);
}
