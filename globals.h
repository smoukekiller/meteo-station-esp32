#ifndef GLOBALS_H
#define GLOBSLS_H
#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

extern bool is_connected;
extern uint64_t wifi_reconnect_timer;
extern uint64_t dht_sensor_timer; 
extern DHT dht;
extern float humidity;
extern float temperature;


#endif
