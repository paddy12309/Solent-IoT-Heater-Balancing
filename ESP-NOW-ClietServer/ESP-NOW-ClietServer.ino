#include <WiFi.h>
#include <WebServer.h>

// Configuration
#define ROLE_CLIENT  // Comment this line to compile as Master

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
const int sensorPin = 34;  // Example GPIO pin for the sensor

#ifdef ROLE_CLIENT
const char* serverIP = "192.168.1.100"; // Replace with Master's IP
const int serverPort = 8080;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi as Client.");
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  WiFiClient client;
  if (client.connect(serverIP, serverPort)) {
    client.println(String(sensorValue));
    Serial.println("Sent data: " + String(sensorValue));
    client.stop();
  } else {
    Serial.println("Failed to connect to Master.");
  }
  delay(2000);  // Send data every 2 seconds
}

#else
WebServer server(80);
int sensorValue = 0;

void handleRoot() {
  String html = "<html><body><h1>ESP32 Sensor Reading</h1>";
  html += "<p>Sensor Value: " + String(sensorValue) + "</p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Master running at: ");
  Serial.println(IP);
  
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String data = client.readStringUntil('\n');
    sensorValue = data.toInt();
    Serial.println("Received data: " + String(sensorValue));
  }
  server.handleClient();
}
#endif
