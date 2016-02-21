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
     if (_esp -> joinAP(NETWORK_SSID, NETWORK_PASSWORD)) {
        // success
    } else {
        // failure
    }

    if (_esp -> setOprToStationSoftAP()) {
        // success
    } else {
        // failure
    }

    if (_esp -> disableMUX()) {
      // success
    } else {
      // failure
    }
 }
 
 void Network::send(String content) {
    uint8_t buffer[1024] = {0};

    if (_esp -> createTCP(HOST_NAME, HOST_PORT)) {
        // success
    } else {
        // failure
    }

    char *hello = "GET / HTTP/1.1\r\nHost: www.baidu.com\r\nConnection: close\r\n\r\n";
    _esp -> send((const uint8_t*)hello, strlen(hello));

    if (_esp -> releaseTCP()) {
        Serial.print("release tcp ok\r\n");
    } else {
        Serial.print("release tcp err\r\n");
    }
 }
