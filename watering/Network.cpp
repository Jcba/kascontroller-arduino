/*
 * Network.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: Job Bakker
 */
 
 #include "Network.h"
 
 Network::Network(uint8_t rx, uint8_t tx, uint8_t enable_pin) {
     _enable_pin = enable_pin;
     pinMode(_enable_pin, OUTPUT);
     _rx = rx;
     _tx = tx;
 }
 
 void Network::enable() {
     digitalWrite(enable_pin, HIGH);
 }
 
 void Network::disable() {
     digitalWrite(enable_pin, LOW);
 }
 
 void Network::connect(char* address) {
     
 }
 
 void Network::sendJson(char* json) {
 
 }