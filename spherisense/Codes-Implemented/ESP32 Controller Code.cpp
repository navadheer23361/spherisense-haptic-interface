/*
 * ESP32 Joystick Controller
 * Sends joystick X/Y values via UDP to ESP8266 motor receiver.
 *
 * Format sent:
 * M:x.xx,y.yy
 * Example:
 * M:0.45,-0.80
 */

#include <WiFi.h>
#include <WiFiUdp.h>

// -------- USER CONFIG ----------
const char* WIFI_SSID = "neeraj's MSI";
const char* WIFI_PASS = "12345678";

const char* UDP_IP = "192.168.137.100"; // ESP8266 IP
const int UDP_PORT = 4210;

// Joystick Pins
const int JOY_X = 34;
const int JOY_Y = 35;

WiFiUDP udp;

void setup() {

  Serial.begin(115200);

  pinMode(JOY_X, INPUT);
  pinMode(JOY_Y, INPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");
  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.localIP());

  udp.begin(UDP_PORT);
}

void loop() {

  int rawX = analogRead(JOY_X);
  int rawY = analogRead(JOY_Y);

  float x = map(rawX, 0, 4095, -1000, 1000) / 1000.0;
  float y = map(rawY, 0, 4095, -1000, 1000) / 1000.0;

  // Deadzone
  if (abs(x) < 0.05) x = 0;
  if (abs(y) < 0.05) y = 0;

  String msg = "M:" + String(x, 2) + "," + String(y, 2);

  udp.beginPacket(UDP_IP, UDP_PORT);
  udp.print(msg);
  udp.endPacket();

  Serial.println(msg);

  delay(50);
}