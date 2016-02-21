#include "DHT.h"
#include "SoilMoisture.h"
#include "ControlBoardPins.h"
#include "Configuration.h"
#include "Network.h"
#include "Pump.h"
#include "Display.h"

DHT dht(DHT_SENSOR_PIN, DHT11);

SoilMoisture soilMoisture(SOIL_SENSOR_PIN);

Network network(RX_PIN, TX_PIN, NETWORK_ENABLE_PIN, Serial);

Pump waterPump(MOTOR_ENA, MOTOR_IN1, MOTOR_IN2);

//Display display();

unsigned long lastNetworkUpdate;
unsigned long lastPumpAction;

void setup() {
	lastNetworkUpdate = millis();
	lastPumpAction = millis();
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
	
	if(millis() - lastNetworkUpdate > NETWORK_UPDATE_INTERVAL) {
		Serial.print("informing server");
		informServer(h, t, moisture);
		lastNetworkUpdate = millis();
	}
	
	if(moisture < MOISTURE_THRESHOLD and (millis() - lastPumpAction) > MIN_PUMP_INTERVAL) {
		Serial.print("Watering");
		waterPump.giveWater(10);
		lastPumpAction = millis();
	}

}

/**
 * Simple inform server method which informs a listening server listening on NETWORK_ADDRESS of
 * read sensor values in JSON format
 */
void informServer(float humidity, float temperature, float moisture) {
	network.enable(); // this can take a while (needs to boot and reconnect to server)
	network.connect(NETWORK_ADDRESS);
	network.send("{humidity:"+String(humidity, PRESENTATION_FLOAT_DECIMALS)+
		",temperature:"+String(temperature, PRESENTATION_FLOAT_DECIMALS)+
		",moisture:"+String(moisture, PRESENTATION_FLOAT_DECIMALS)+
		"}");
	network.disable(); // save energy (turns network interface off)
}
