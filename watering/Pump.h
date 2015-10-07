/*
 * Pump.h
 *
 *  Created on: Oct 4, 2015
 *      Author: Job Bakker
 */

#ifndef PUMP_H_
#define PUMP_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class Pump {
public:
	Pump(uint8_t pin);
	void giveWater(float amount);

private:
	uint8_t _pin;

};

#endif /* PUMP_H_ */
