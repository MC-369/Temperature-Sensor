#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define THERMISTOR_PIN 35   // GPIO where thermistor is connected
#define SERIES_RESISTOR 10000  // 10kΩ resistor
#define VCC 3.3  // ESP32 operating voltage

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  int analogValue = analogRead(THERMISTOR_PIN);  // Read ADC value
  float voltage = analogValue * (VCC / 4095.0);  // Convert ADC value to voltage
  float resistance = (VCC * SERIES_RESISTOR / voltage) - SERIES_RESISTOR;  

  // Simple temperature conversion (approximate)
  float temperature = (resistance - 10000) / 50 + 25;  

  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(" | Temp: ");
  Serial.print(temperature);
  Serial.println(" C");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C  ");

  delay(1000);
}
