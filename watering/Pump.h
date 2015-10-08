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
	//instantiate a pump with L298N interfacing pins
	Pump(uint8_t pwm, uint8_t in1, uint8_t in2);

	void giveWater(float amount);

private:
	uint8_t _pwm;
	uint8_t _in1;
	uint8_t _in2;

};

#endif /* PUMP_H_ */
