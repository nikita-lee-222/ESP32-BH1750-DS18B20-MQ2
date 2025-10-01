# ESP32-BH1750-DS18B20-MQ2

ESP32 project reading BH1750, DS18B20, and MQ-2 sensors with Serial output.
- BH1750 - light intensity sensor (lux)
- DS18B20 - temperature sensor
- MQ-2 – gas sensor (analog value)
Data is displayed every 5 seconds in the Serial Monitor.

## Connections

BH1750 (I2C):
- SDA → D21
- SCL → D22
- VCC → 3.3V
- GND → GND
- ADDR → GND or VCC (address 0x23 or 0x5C)

DS18B20 (1-Wire):
Attention! 4.7kΩ pull-up resistor should be installed; just check if your board already has it.
- DATA → D4
- VCC → 3.3V
- GND → GND
  
MQ-2 (Analog/Digital):
- AO → D34 (analog input)
- DO → optional digital input
- VCC → 5V
- GND → GND

## How to use?

1. Connect all sensors to the ESP32;
2. Open Arduino IDE;
3. Install the required libraries:
- BH1750 [Christopher Laws](https://docs.arduino.cc/libraries/bh1750/)
- DallasTemperature [Miles Burton, Tim Newsome, Guil Barros, Rob Tillaart](https://docs.arduino.cc/libraries/dallastemperature/)
- OneWire [Jim Studt, Tom Pollard, Robin James, Glenn Trewitt, Jason Dangel, Guillermo Lovato, Paul Stoffregen, Scott Roberts, Bertrik Sikken, Mark Tillotson, Ken Butcher, Roger Clark, Love Nystrom](https://docs.arduino.cc/libraries/onewire/)
4. Upload the sketch to the ESP32;
5. Open the Serial Monitor (115200 baud) to view sensor readings.

## Possible Improvements

- Save the log to cloudstorage.
- Display data on screen or web page.
- Set alert thresholds for the MQ-2 sensor.
