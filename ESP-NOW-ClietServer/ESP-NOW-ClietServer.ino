#include <esp_now.h>
#include <WiFi.h>
#include <WebServer.h>

// Configuration
const int modePin = 4;  // Pin to select mode (HIGH = Master, LOW = Client)
const int sensorPin = 34;  // Example GPIO pin for the sensor
const uint8_t masterAddress[] = {0x24, 0x6F, 0x28, 0xAA, 0xBB, 0xCC}; // Replace with Master's MAC
bool isMaster = false;

// Web server (used only in Master mode)
WebServer server(80);

// Data structure for ESP-NOW
typedef struct {
  int sensorValue;
} SensorData;

SensorData dataToSend;
SensorData receivedData;

// Callback for ESP-NOW send (Client mode)
void onSent(const uint8_t *macAddr, esp_now_send_status_t status) {
  Serial.print("Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Failed");
}

// Callback for ESP-NOW receive (Master mode)
void onReceive(const uint8_t *macAddr, const uint8_t *incomingData, int len) {
  memcpy(&receivedData, incomingData, sizeof(receivedData));
  Serial.println("Received sensor value: " + String(receivedData.sensorValue));
}

// Handle the web server root page (Master mode)
void handleRoot() {
  String html = "<html><body><h1>ESP32 Sensor Data</h1>";
  html += "<p>Sensor Value: " + String(receivedData.sensorValue) + "</p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

// Setup for Master mode
void setupMaster() {
  Serial.println("Starting in Master mode");

  // Set up Wi-Fi Access Point
  WiFi.mode(WIFI_AP);
  WiFi.softAP("ESP32_Master", "12345678");
  Serial.println("Wi-Fi AP started. Connect to http://192.168.4.1");

  // Start the web server
  server.on("/", handleRoot);
  server.begin();

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Initialization Failed");
    return;
  }

  // Register the receive callback
  esp_now_register_recv_cb(onReceive);
}

// Setup for Client mode
void setupClient() {
  Serial.println("Starting in Client mode");

  // Initialize Wi-Fi in station mode (required for ESP-NOW)
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW Initialization Failed");
    return;
  }

  // Register the send callback
  esp_now_register_send_cb(onSent);

  // Add the Master as a peer
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, masterAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void setup() {
  Serial.begin(115200);

  // Configure mode selection pin
  pinMode(modePin, INPUT_PULLUP);
  isMaster = digitalRead(modePin);  // HIGH = Master, LOW = Client

  // Initialize the appropriate mode
  if (isMaster) {
    setupMaster();
  } else {
    setupClient();
  }
}

void loop() {
  if (isMaster) {
    // Handle the web server
    server.handleClient();
  } else {
    // Read sensor data and send to Master
    dataToSend.sensorValue = analogRead(sensorPin);
    esp_err_t result = esp_now_send(masterAddress, (uint8_t *)&dataToSend, sizeof(dataToSend));
    if (result == ESP_OK) {
      Serial.println("Sent data: " + String(dataToSend.sensorValue));
    } else {
      Serial.println("Error sending data");
    }
    delay(2000);  // Send data every 2 seconds
  }
}
