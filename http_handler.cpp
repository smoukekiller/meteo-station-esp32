#include <HTTPClient.h>
#include "globals.h"
#include "config.h"
#include "credentials.h"

void send_data() {
  if ((http_request_timer + HTTP_REQUEST_TIME) <= millis()) {
    if (is_connected) {
      HTTPClient http;
      
      http.begin(SERVERURL);
      http.addHeader("Content-Type", "application/json");
      http.addHeader("Authorization", SECRET_KEY);
      String payload = "{\"temperature\": " + String(temperature) +
                       ", \"humidity\": " + String(humidity) + "}";

      int httpResponseCode = http.POST(payload);
      
      if (httpResponseCode > 0) {
        Serial.printf("HTTP Response code: %d\n", httpResponseCode);
        String response = http.getString();
        Serial.println("Response: " + response);
      } else {
        Serial.printf("Error code: %d\n", httpResponseCode);
      }
      http.end();
    }
    http_request_timer = millis();
  }
}
