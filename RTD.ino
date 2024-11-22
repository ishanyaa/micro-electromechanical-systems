#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64   // OLED display height, in pixels

// Create an instance of the OLED display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin definitions
const int potPin = 34;  // GPIO pin for potentiometer (ADC pin)

void setup() {
  // Initialize the serial monitor for debugging
  Serial.begin(115200);

  // Initialize the OLED display with I2C address
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Use 0x3C for the OLED I2C address
  display.clearDisplay();
  
  // Display initial message
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("ESP32 ADC Readings");
  display.display();
  delay(2000); // Pause for 2 seconds
}

void loop() {
  int analogValue = analogRead(potPin);  // Read the analog value from the potentiometer
  float voltage = analogValue * (3.3 / 4095.0); // Convert to voltage (0-3.3V)
  
  // Clear the display
  display.clearDisplay();
  
  // Display the readings
  display.setCursor(0, 0);
  display.print("Analog Value: ");
  display.println(analogValue);
  display.print("Voltage: ");
  display.print(voltage);
  display.println(" V");
  
  // Refresh the display
  display.display();

  delay(500);  // Update every half second
}
