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
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 15 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    // Recomendar siembra de flores
    Serial.println("Recomendar siembra de flores");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 18 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas
    Serial.println("Recomendar siembra de hortalizas");
  } else if (pH >= 5.0 && pH <= 6.0 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    // Recomendar siembra de cítricos
    Serial.println("Recomendar siembra de cítricos");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas de hoja
    Serial.println("Recomendar siembra de hortalizas de hoja");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de legumbres
    Serial.println("Recomendar siembra de legumbres");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 22 && temperature <= 28 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas de raíz
    Serial.println("Recomendar siembra de hortalizas de raíz");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hierbas aromáticas
    Serial.println("Recomendar siembra de hierbas aromáticas");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de tubérculos
    Serial.println("Recomendar siembra de tubérculos");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de árboles frutales
    Serial.println("Recomendar siembra de árboles frutales");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de frutos secos
    Serial.println("Recomendar siembra de frutos secos");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de especias
    Serial.println("Recomendar siembra de especias");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas medicinales
    Serial.println("Recomendar siembra de plantas medicinales");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas tropicales
    Serial.println("Recomendar siembra de plantas tropicales");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de bayas
    Serial.println("Recomendar siembra de bayas");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de frutos exóticos
    Serial.println("Recomendar siembra de frutos exóticos");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 22 && temperature <= 28 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas de bulbo
    Serial.println("Recomendar siembra de hortalizas de bulbo");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de hortalizas de tallo
    Serial.println("Recomendar siembra de hortalizas de tallo");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de granos
    Serial.println("Recomendar siembra de granos");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas ornamentales
    Serial.println("Recomendar siembra de plantas ornamentales");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de árboles ornamentales
    Serial.println("Recomendar siembra de árboles ornamentales");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de sombra
    Serial.println("Recomendar siembra de plantas de sombra");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de sol
    Serial.println("Recomendar siembra de plantas de sol");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas acuáticas
    Serial.println("Recomendar siembra de plantas acuáticas");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de enredaderas
    Serial.println("Recomendar siembra de enredaderas");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de interior
    Serial.println("Recomendar siembra de plantas de interior");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de arbustos
    Serial.println("Recomendar siembra de arbustos");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de árboles frutales enanos
    Serial.println("Recomendar siembra de árboles frutales enanos");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 22 && temperature <= 28 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de estación
    Serial.println("Recomendar siembra de plantas de estación");
  } else if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de clima cálido
    Serial.println("Recomendar siembra de plantas de clima cálido");
  } else if (pH >= 6.5 && pH <= 7.5 && temperature >= 20 && temperature <= 30 && humidity >= 50 && humidity <= 70 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de clima frío
    Serial.println("Recomendar siembra de plantas de clima frío");
  } else if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    // Recomendar siembra de plantas de climas templados
    Serial.println("Recomendar siembra de plantas de climas templados");
  } else {
    // No recomendar siembra de cultivos
    Serial.println("No recomendar siembra de cultivos");
  }

  delay(1000);
}
