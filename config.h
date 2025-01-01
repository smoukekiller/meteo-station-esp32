#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>

#define WIFI_RECONNECT_TIME 5000 //changes time between reinitializing wifi
#define DHT_SENSOR_TIME 1000 //time between DHT sensor readings 
#define HTTP_REQUEST_TIME 15000 //time between HTTP requests 

#define DHTTYPE DHT11 //DHT sensor type
#define DHTPIN 26 //DHT sensor pin


#endif
