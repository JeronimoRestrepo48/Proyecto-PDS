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
  float pH = analogRead(A0);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float pressure = bme.readPressure() / 100.0F;
  float altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);

  // Análisis de datos
  if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de frutas
    Serial.println("Recomendar siembra de frutas");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de verduras
    Serial.println("Recomendar siembra de verduras");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de flores
    Serial.println("Recomendar siembra de flores");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 22 && temperature <= 30 && humidity >= 60 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas
    Serial.println("Recomendar siembra de hortalizas");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hierbas
    Serial.println("Recomendar siembra de hierbas");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 28 && humidity >= 60 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de legumbres
    Serial.println("Recomendar siembra de legumbres");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 18 && temperature <= 25 && humidity >= 70 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de tubérculos
    Serial.println("Recomendar siembra de tubérculos");
  } // Añadir más condiciones para otros tipos de cultivos aquí
  else {
    // No recomendar siembra de cultivos
    Serial.println("No recomendar siembra de cultivos");
  }

  delay(1000);
}
