// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6)
const int potPin = 34;

// Variable for storing the potentiometer value
int potValue = 0;

// Reference voltage of the ESP32 (3.3V)
const float Vref = 3.3;

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud
  delay(1000);           // Delay for serial connection stability
}

void loop() {
  // Reading potentiometer value
  potValue = analogRead(potPin);

  // Convert the ADC reading to a voltage
  float voltage = (potValue / 4095.0) * Vref;

  // Display the ADC value and the voltage
  Serial.print("ADC Value: ");
  Serial.print(potValue);
  Serial.print(" | Voltage: ");
  Serial.println(voltage, 3);  // Print voltage with 3 decimal places

  delay(500);  // Delay for readability
}
