#include "DHT.h"
#include "SoilMoisture.h"
#include "ControlBoardPins.h"

DHT dht(DHT_SENSOR_PIN, DHT11);

SoilMoisture soilMoisture(SOIL_SENSOR_PIN);

void setup() {
	Serial.begin(9600);
	Serial.println("test");
	dht.begin();
}

void loop() {
	delay(2000);

	// Reading temperature or humidity takes about 250 milliseconds!
	// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
	float h = dht.readHumidity();
	// Read temperature as Celsius (the default)
	float t = dht.readTemperature();

	float moisture = soilMoisture.readMoisture();

	// Check if any reads failed and exit early (to try again).
	if (isnan(h) || isnan(t)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}

	Serial.print("Humidity: ");
	Serial.print(h);
	Serial.print(" %\t");
	Serial.print("Temperature: ");
	Serial.print(t);
	Serial.print(" *C ");
	Serial.print("Moisture: ");
	Serial.println(moisture);
}
