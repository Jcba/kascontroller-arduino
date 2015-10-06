/*
 * Network.h
 *
 *  Created on: Oct 5, 2015
 *      Author: Job Bakker
 *
 *  Network interfacing code
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class Network {
public:
	Network(uint8_t rx, uint8_t tx, uint8_t enable_pin);
	/* enables the network interface */
	void enable();
	/* disables the network interface */
	void disable();
	/* sets up a connection with a receiving host (a fixed IP where a server
	    is listening)
	 */
	void connect(char* reciever);
	/* sends a JSON string to the reciever */
	void sendJson(char* json);

private:
	uint8_t _rx; //rx pin
	uint8_t _tx; //tx pin
	uint8_t _enable_pin;
};


#endif /* NETWORK_H_ */
