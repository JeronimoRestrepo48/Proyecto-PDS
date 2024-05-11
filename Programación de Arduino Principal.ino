#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "SPI.h"
#include <Adafruit_BME280.h>
#include <DHT.h>
#include <WiFi.h>

// Configuración de sensores y conexión Wi-Fi
#define DHTPIN 4
#define DHTTYPE DHT11
#define BME_SCK 13 // Serial Clock
#define BME_MISO 12 // Serial Data Out
#define BME_MOSI 11 // Serial Data In
#define BME_CS 10 // Chip Select
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);
const char* ssid = "paula angel";
const char* password = "32184346";

void setup() {
  Serial.begin(115200);
  dht.begin();
  bme.begin(0x76);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to Wi-Fi");
}

void loop() {
  float pH = analogRead(A0) / 1024.0 * 14.0; // Ajustar para obtener un valor de pH entre 0 y 14
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float pressure = bme.readPressure() / 100.0F;

  // Enviar datos a Processing
  Serial.print("pH:");
  Serial.println(pH);
  Serial.print("temp:");
  Serial.println(temperature);
  Serial.print("hum:");
  Serial.println(humidity);
  Serial.print("press:");
  Serial.println(pressure);

  delay(1000);
}
