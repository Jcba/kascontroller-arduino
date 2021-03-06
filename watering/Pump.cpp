/*
 * Pump.cpp
 *
 *  Created on: Oct 4, 2015
 *      Author: Job Bakker
 */
#include "Pump.h"

Pump::Pump(uint8_t pwm, uint8_t in1, uint8_t in2){
	_pwm = pwm;
	_in1 = in1;
	_in2 = in2;
	pinMode(_pwm, OUTPUT);
	pinMode(_in1, OUTPUT);
	pinMode(_in2, OUTPUT);
}

void Pump::giveWater(float amount){
  Serial.print("Water");
	unsigned long time = millis();
	digitalWrite(_in1, HIGH);
	digitalWrite(_in2, LOW);
	digitalWrite(_pwm, HIGH);
	while(millis()-time < amount*1000);
  Serial.print("Stop water");
	digitalWrite(_in1, LOW);
	digitalWrite(_in2, LOW);
	digitalWrite(_pwm, LOW);
}




