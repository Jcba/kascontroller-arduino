/*
 * Network.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: Job Bakker
 */
 
#include "Network.h"
#include "ESP8266.h"
 
 Network::Network(uint8_t rx, uint8_t tx, uint8_t enable_pin, HardwareSerial serial) {
     _enable_pin = enable_pin;
     pinMode(_enable_pin, OUTPUT);
     _rx = rx;
     _tx = tx;
     _esp = new ESP8266(serial);
 }
 
 void Network::enable() {
     digitalWrite(_enable_pin, HIGH);
 }
 
 void Network::disable() {
     digitalWrite(_enable_pin, LOW);
 }
 
 void Network::connect(String address) {
     
 }
 
 void Network::sendJson(String json) {
 
 }
