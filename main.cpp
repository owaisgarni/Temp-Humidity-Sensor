#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2       // Define the pin for the DHT11 sensor
#define DHTTYPE DHT11  // DHT sensor type

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 6); // LCD connections (RS, E, D4, D5, D6, D7)

void setup() {
  dht.begin();
  lcd.begin(16, 2);  // Initialize the LCD
  lcd.clear();       // Clear the LCD screen
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
}

void loop() {
  float temperature = dht.readTemperature();  // Read temperature
  float humidity = dht.readHumidity();        // Read humidity

  lcd.setCursor(7, 0);
  lcd.print(temperature, 1);  // Display temperature with one decimal place
  lcd.print("C");

  lcd.setCursor(10, 1);
  lcd.print(humidity, 1);     // Display humidity with one decimal place
  lcd.print("%");

  delay(2000);  // Wait for 2 seconds before taking another reading
}
