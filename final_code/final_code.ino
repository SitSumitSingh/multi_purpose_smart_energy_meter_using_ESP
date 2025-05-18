// ESP32 Energy Meter Project with Blynk, OLED, and Google Sheets Logging

#define BLYNK_TEMPLATE_ID 
#define BLYNK_TEMPLATE_NAME 

#include "EmonLib.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <HTTPClient.h>

// OLED Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Sensor instances
EnergyMonitor emon1;
EnergyMonitor emon2;

// WiFi & Blynk credentials
const char* auth = "*auth*";
const char* ssid = "realme C11";
const char* password = "12345678";

// Google Sheets Web App URL
String googleSheetsURL = "*google sheet appscript token*";

// Sensor and Relay Pins
const int voltagePin1 = 32;
const int currentPin1 = 34;
const int voltagePin2 = 33;
const int currentPin2 = 35;
const int relay1 = 25;
const int relay2 = 26;

// Tariff
const float costPerKWh = 10;

// Timing
unsigned long previousMillis = 0;
const long interval = 10000;

float totalEnergy1 = 0, totalEnergy2 = 0;
float totalCost1 = 0, totalCost2 = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(10); 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Blynk.begin(auth, ssid, password);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Smart Energy Meter");
  display.display();
  delay(1000);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);

  emon1.voltage(voltagePin1, 570, 1);
  emon1.current(currentPin1, 200);
  emon2.voltage(voltagePin2, 570, 1);
  emon2.current(currentPin2, 110);
}

void loop() {
  Blynk.run();

  emon1.calcVI(20, 2000);
  emon2.calcVI(20, 2000);

  float voltage1 = fabs(emon1.Vrms);
  float current1 = fabs(emon1.Irms);
  float realPower1 = fabs(emon1.realPower);
  float apparentPower1 = fabs(emon1.apparentPower);

  float voltage2 = fabs(emon2.Vrms);
  float current2 = fabs(emon2.Irms);
  float realPower2 = fabs(emon2.realPower);
  float apparentPower2 = fabs(emon2.apparentPower);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    totalEnergy1 += (realPower1 * (interval / 3600000.0)) / 1000;
    totalEnergy2 += (realPower2 * (interval / 3600000.0)) / 1000;

    totalEnergy1 = fabs(totalEnergy1);
    totalEnergy2 = fabs(totalEnergy2);
    totalCost1 = fabs(totalEnergy1 * costPerKWh);
    totalCost2 = fabs(totalEnergy2 * costPerKWh);

    sendToGoogleSheets(voltage1, current1, realPower1, apparentPower1,
                       voltage2, current2, realPower2, apparentPower2,
                       totalEnergy1, totalEnergy2, totalCost1, totalCost2);
  }

  digitalWrite(relay1, (realPower1 > 800) ? HIGH : LOW);
  digitalWrite(relay2, (realPower2 > 1400) ? HIGH : LOW);

  Blynk.virtualWrite(V0, voltage1);
  Blynk.virtualWrite(V1, current1);
  Blynk.virtualWrite(V2, totalEnergy1);
  Blynk.virtualWrite(V3, emon1.powerFactor);
  Blynk.virtualWrite(V4, current2);
  Blynk.virtualWrite(V5, totalEnergy2);
  Blynk.virtualWrite(V6, emon2.powerFactor);
  Blynk.virtualWrite(V7, totalCost1);
  Blynk.virtualWrite(V8, totalCost2);
  Blynk.virtualWrite(V9, relay1);
  Blynk.virtualWrite(V10, relay2);
  Blynk.virtualWrite(V11, voltage2);

  // OLED Display Load 1
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Load 1:");
  display.print("V: "); display.print(voltage1); display.println(" V");
  display.print("I: "); display.print(current1); display.println(" A");
  display.print("P: "); display.print(realPower1); display.println(" W");
  display.print("E: "); display.print(totalEnergy1, 3); display.println(" kWh");
  display.display();
  delay(2000);

  // OLED Display Load 2
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Load 2:");
  display.print("V: "); display.print(voltage2); display.println(" V");
  display.print("I: "); display.print(current2); display.println(" A");
  display.print("P: "); display.print(realPower2); display.println(" W");
  display.print("E: "); display.print(totalEnergy2, 3); display.println(" kWh");
  display.display();
  delay(2000);
}

void sendToGoogleSheets(float voltage1, float current1, float realPower1, float apparentPower1,
                        float voltage2, float current2, float realPower2, float apparentPower2,
                        float energy1, float energy2, float cost1, float cost2) {
  HTTPClient http;
  http.setTimeout(3000);

  String url = googleSheetsURL + "?v1=" + String(voltage1) +
               "&i1=" + String(current1) +
               "&rp1=" + String(realPower1) +
               "&ap1=" + String(apparentPower1) +
               "&v2=" + String(voltage2) +
               "&i2=" + String(current2) +
               "&rp2=" + String(realPower2) +
               "&ap2=" + String(apparentPower2) +
               "&e1=" + String(energy1, 3) +
               "&e2=" + String(energy2, 3) +
               "&c1=" + String(cost1, 2) +
               "&c2=" + String(cost2, 2);

  http.begin(url);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    Serial.println("Data sent to Google Sheets.");
  } else {
    Serial.println("Error sending data.");
  }

  http.end();
}
