/*
 * SoilMoisture.cpp
 *
 *  Created on: Oct 4, 2015
 *      Author: Job Bakker
 */

#include "SoilMoisture.h"

SoilMoisture::SoilMoisture(uint8_t pin) {
	_pin = pin;
}

float SoilMoisture::readMoisture() {
	return 1.0-(analogRead(_pin)/(float)1023);
}





