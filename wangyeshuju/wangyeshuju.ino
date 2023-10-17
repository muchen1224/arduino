//利用esp01s自带的网页，将dht11温湿度数据显示出来。
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

// Replace with your network credentials
const char* ssid = "mu";
const char* password = "87654321";

// Create a web server on port 80
ESP8266WebServer server(80);

// Create a DHT object
DHT dht(2, DHT11);

void setup() {
  // Connect to Wi-Fi network with SSID and password
  Serial.begin(9600);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Initialize DHT sensor
  dht.begin();

  // Set up web page response
  server.on("/", [](){
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    server.send(200, "text/html", "<html><body><h1>ESP8266 DHT11 Web Server</h1><p>Temperature: " + String(temperature) + " &deg;C</p><p>Humidity: " + String(humidity) + " %</p></body></html>");
  });

  // Start server
  server.begin();
}

void loop() {
  // Listen for incoming clients
  server.handleClient();
}
