#include <Arduino.h>
#include <DHT.h>

// DHT data pin set to digital pin 2
// Define the DHT data pin (Use digital pin 2)
#define DHTPIN 2

// DHT sensor type set to DHT11
// Define the DHT sensor type (DHT11)
#define DHTTYPE DHT11

// Instantiate DHT object using DHTPIN and DHTTYPE
// Create a DHT object using the defined pin and sensor type
DHT dht(DHTPIN, DHTTYPE);

void setup() {

    // Initialize Serial at 9600 baud
    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // Initialize the DHT sensor driver
    // Initialize the DHT sensor
    dht.begin();

    // Print system initialization messages
    // Print a system initialization message
    Serial.println("DHT11 Temperature and Humidity Monitoring System");
    Serial.println("Initializing...");
}

void loop() {

    // Read humidity from DHT sensor
    // Read humidity value from sensor
    float humidity = dht.readHumidity();

    // TODO 8:
    // Read temperature value from sensor
    float temperature = dht.readTemperature();

    // TODO 9:
    // Check if either reading failed using isnan()
    // If failed, print error message and return
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // TODO 10:
    // Print formatted temperature and humidity values
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C  |  Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // TODO 11:
    // Add a 2-second delay before next reading
    delay(2000);
}