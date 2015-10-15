/*
 * Display.h
 *
 *  Created on: Oct 6, 2015
 *      Author: Job Bakker
 *
 *  Display code
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "U8glib.h"

class Display {
public:
/** u8glib reference is dependent on used screen **/
  Display(U8GLIB* u8glib);
  void writeTemperature(float temperature);
  void writeHumidity(float humidity);
  
private:
  U8GLIB * _u8glib;

};

#endif /* DISPLAY_H_ */
