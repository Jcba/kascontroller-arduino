/*
 * ControlBoardPins.h
 *
 *  Created on: Oct 6, 2015
 *      Author: Job Bakker
 *
 *  Pin layout of control board
 */
 
#ifndef CONTROLBOARDPINS_H_
#define CONTROLBOARDPINS_H_

/*
 * RX/TX pins for use with the networking interface
 */
#define RX_PIN 0
#define TX_PIN 1

/*
 * Network interface pins
 */
#define NETWORK_ENABLE_PIN 9 //dummy value

/*
 * DHT sensor is used to read air humidity and temperature
 */
#define DHT_SENSOR_PIN 2

/*
 * Soil sensor 1 
 */
#define SOIL_SENSOR_PIN 16

/*
 * Water pump motor 1
 */
#define MOTOR_ENA 4 //should be a PWM pin
#define MOTOR_IN1 5
#define MOTOR_IN2 6

#endif //CONTROLBOARDPINS_H_
