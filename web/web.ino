#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>

#define WIFI_SSID "mu"
#define WIFI_PASSWORD "87654321"
#define SERVER_IP "47.120.1.192"
#define SERVER_PORT 8080

#define DHT_PIN 2
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if reading is valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read temperature and humidity from DHT sensor");
    return;
  }

  // Create HTTP client and request
  WiFiClient client;
  HTTPClient http;
  String url = "http://" + String(SERVER_IP) + ":" + String(SERVER_PORT) + "/temperature";
  http.begin(client, url);

  // Add headers
  http.addHeader("Content-Type", "application/json");

  // Create JSON payload
  String payload = "{\"temperature\":" + String(temperature) + ",\"humidity\":" + String(humidity) + "}";

  // Send request and print response
  int httpCode = http.POST(payload);
  if (httpCode > 0) {
    String response = http.getString();
    Serial.println("HTTP response: " + response);
  } else {
    Serial.println("Failed to send HTTP request");
  }

  http.end();
  
  delay(60000); // Wait for 60 seconds
}
