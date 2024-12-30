#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "globals.h"
#include "config.h"

void read_dht_sensor()
{   if ((dht_sensor_timer + DHT_SENSOR_TIME) <= millis())
  {
  

      float temp_humidity = dht.readHumidity();
      float temp_temperature = dht.readTemperature();
      if (isnan(temp_humidity) || isnan(temp_temperature))
      {
        Serial.println("Failed to read DHT sensor");
        return;
      }
      humidity = temp_humidity;
      temperature = temp_temperature;
      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.println(" °C");
      dht_sensor_timer = millis();
  }
}
