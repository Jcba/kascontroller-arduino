/*
 * Display.cpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Job Bakker
 */

#include "Display.h"
#include "U8glib.h"
#include "Configuration.h"

Display::Display(U8GLIB* u8glib) {
	_u8glib = u8glib;
	_u8glib->setFont(u8g_font_gdr25);
}

void Display::writeTemperature(float temperature) {
	_u8glib->drawStr(5, 40, (String(temperature, PRESENTATION_FLOAT_DECIMALS)+" C").c_str());
}

void Display::writeHumidity(float humidity) {
	_u8glib->drawStr(5, 80, (String(humidity, PRESENTATION_FLOAT_DECIMALS)+" %").c_str());
}






