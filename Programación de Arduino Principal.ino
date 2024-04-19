#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <DHT.h>
#include <WiFi.h>

// Configuración de sensores y conexión Wi-Fi
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BME280 bme;
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

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
  float altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);

  // Enviar datos a Processing
  Serial.print("pH:");
  Serial.println(pH);
  Serial.print("temp:");
  Serial.println(temperature);
  Serial.print("hum:");
  Serial.println(humidity);
  Serial.print("press:");
  Serial.println(pressure);
  Serial.print("alt:");
  Serial.println(altitude);

  delay(1000);
}
