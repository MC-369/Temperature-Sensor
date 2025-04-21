# Temperature-Sensor
ESP32-Based Temperature Sensor with LCD Display
A working temperature sensing prototype using an ESP32, NTC thermistor, and JHD 16x2 I2C LCD display, focusing on circuit wiring and functionality testing. The goal is to create a compact, standalone temperature monitoring device.

🔌 Hardware (Prototype Phase):
ESP32 microcontroller for data acquisition and processing

NTC thermistor in a voltage divider configuration with a 10kΩ resistor

Voltage regulation handled by:

LTS875 (5V) for powering the display

AMS1117 (3.3V) for the ESP32

Additional capacitors for power filtering and resistors for accuracy

Connected via jumper wires on a breadboard to validate the wiring and circuit behavior

💻 Software Logic:
Reads analog input from the thermistor (GPIO 35)

Converts the raw ADC value to an approximate temperature

Displays real-time temperature readings on the LCD

Sends debug info to the Serial Monitor for testing


