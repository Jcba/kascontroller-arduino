/*
 * SoilMoisture.h
 *
 *  Created on: Oct 4, 2015
 *      Author: Job Bakker
 *
 *  Soil moisture measurement code
 */

#ifndef SOILMOISTURE_H_
#define SOILMOISTURE_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class SoilMoisture {
public:
	SoilMoisture(uint8_t pin);
	float readMoisture();

private:
	uint8_t _pin;
};



#endif /* SOILMOISTURE_H_ */
