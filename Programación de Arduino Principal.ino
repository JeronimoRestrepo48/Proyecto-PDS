
/*Incluimos primero las librerías instaladas*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "UbidotsEsp32Mqtt.h"

// Configuración de sensores 
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5
Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);
#define SEALEVELPRESSURE_HPA (1013.25)


/*Definimos primero el Token que nos brinda la plataforma Ubidots para hacer la conexión*/
const char *UBIDOTS_TOKEN = "BBUS-V5lZh5cBtTxP1NM6A1vpsWyWjlncZr";
/*Definimos SSID y PASSWORD de nuestra red WiFi*/
const char *WIFI_SSID = "paula angel";      
const char *WIFI_PASS = "32184346";     
/*Definimos el nombre de nuestro dispositivo, el cual aparecerá en la plataforma Ubidots*/
const char *DEVICE_LABEL = "arduino_main";
/*Definimos las variables que se medirán y que serán publicadas en la plataforma Ubidots*/
const char *VARIABLE_LABEL_1 = "temperature"; 
const char *VARIABLE_LABEL_2 = "humidity"; 
const char *VARIABLE_LABEL_3 = "pressure"; 
const char *VARIABLE_LABEL_4 = "altitude"; 
const char *VARIABLE_LABEL_5 = "ph"; 
/*Definimos la frecuencia de publicación de 5 segundos*/
const int PUBLISH_FREQUENCY = 5000; 
/*Definimos unas variables extra, que incluye la librería*/
unsigned long timer;
uint8_t analogPin = 34; 
/*Definimos que las variables de la librería UBIDOTS trabajarán con el Token*/
Ubidots ubidots(UBIDOTS_TOKEN);

/*La librería nos da una función de Subscripción para mensajes de regreso desde la plataforma Ubidots hacia nuestro circuito*/
void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

/*Definimos la función Setup() para iniciar nuestro circuito*/
void setup()
{
  /*Iniciamos el terminal Serial a 115200*/
  Serial.begin(115200);     
  /*Imprimimos el siguiente texto para asegurar el encendido del circuito*/
  Serial.println("Medición inciada");
  Serial.println("BME280 Encendido");
  /*Iniciamos nuestro sensor DHT11*/
  bme.begin(0x76);
  /*Incluimos un retardo de 1 segundo*/
  delay(1000);

  /*Ahora, se incluye las funciones de conexión de la Plataforma, como la conexión a internet con las credenciales de WiFi*/
  // ubidots.setDebug(true);  //Descomentar esto para que los mensajes de depuración estén disponibles
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASS);
  /*Se inicia la función de subscripción para los mensajes de retorno, que se definió líneas arriba*/
  ubidots.setCallback(callback);
  /*Se incluye las funciones de Setup y Reconnect, predefinidas de la librería*/
  ubidots.setup();
  ubidots.reconnect();
  timer = millis();
}

/*Iniciamos el bucle de la función Loop()*/
void loop()
{
  /*Definimos que, si no se conecta a la plataforma Ubidots, se pasa la función Reconnect() para volver a establecer la conexión*/
  if (!ubidots.connected())
  {
    ubidots.reconnect();
  }
  /*En esta condicional, iniciamos la medición de Temperatura y Humedad del sensor, y la información será enviada a la Plataforma*/
  if (millis() - timer > PUBLISH_FREQUENCY) 
  {
    /*Hacemos la medición de Temperatura y Humedad del sensor, y lo definimos en variables Float */
    float pH = analogRead(analogPin) / 1024.0 * 14.0;
    float temperature = bme.readTemperature();
    float humidity = bme.readHumidity();
    float pressure = bme.readPressure() / 100.0F;
    float altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);

    /*Definimos que el valor de Temperatura será enviado por la variable 1, a la plataforma Ubidots*/
    ubidots.add(VARIABLE_LABEL_1, temperature);
    /*Definimos que el valor de Humedad será enviado por la variable 2, a la plataforma Ubidots*/
    ubidots.add(VARIABLE_LABEL_2, humidity);
    ubidots.add(VARIABLE_LABEL_3, pressure);
    ubidots.add(VARIABLE_LABEL_4, altitude);
    ubidots.add(VARIABLE_LABEL_5, pH);
    /*Hacemos la publicación de los datos en el dispositivo definido*/
    ubidots.publish(DEVICE_LABEL);
    /*Para mostrar los datos, los imprimimos en el terminal Serial*/
    Serial.println("Enviando los datos a Ubidots: ");
    Serial.println("Temperatura: " + String(temperature) + " °C");
    Serial.println("Humedad: " + String(humidity) + " %");
    Serial.println("Presión: " + String(pressure) + " hPa");
    Serial.println("Altitud: " + String(altitude) + " m");
    Serial.println("pH: " + String(pH));
    Serial.println("-----------------------------------------");
    timer = millis();
    // Manzanas
if (pH >= 6.0 && pH <= 7.0 && temperature >= 15 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de manzanas");
}
// Plátanos
if (pH >= 5.5 && pH <= 6.5 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    Serial.println("Recomendar siembra de plátanos");
}
// Tomates
if (pH >= 6.0 && pH <= 7.0 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de tomates");
}
// Uvas
if (pH >= 5.5 && pH <= 6.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    Serial.println("Recomendar siembra de uvas");
}
// Zanahorias
if (pH >= 6.5 && pH <= 7.5 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de zanahorias");
}
// Papas
if (pH >= 5.5 && pH <= 6.5 && temperature >= 20 && temperature <= 30 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de papas");
}
// Cebollas
if (pH >= 6.0 && pH <= 7.0 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de cebollas");
}
// Fresas
if (pH >= 5.5 && pH <= 6.5 && temperature >= 15 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 950 && pressure <= 1020) {
    Serial.println("Recomendar siembra de fresas");
}
// Lechugas
if (pH >= 6.0 && pH <= 7.0 && temperature >= 18 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de lechugas");
}
// Maíz
if (pH >= 5.5 && pH <= 6.5 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de maíz");
}
// Arroz
if (pH >= 6.0 && pH <= 7.0 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de arroz");
}
// Trigo
if (pH >= 6.5 && pH <= 7.5 && temperature >= 15 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de trigo");
}
// Cacao
if (pH >= 5.5 && pH <= 6.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    Serial.println("Recomendar siembra de cacao");
}
// Café
if (pH >= 6.0 && pH <= 7.0 && temperature >= 18 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de café");
}
// Cilantro
if (pH >= 5.5 && pH <= 6.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de cilantro");
}
// Ajo
if (pH >= 6.0 && pH <= 7.0 && temperature >= 18 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de ajo");
}
// Berenjenas
if (pH >= 5.5 && pH <= 6.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de berenjenas");
}
// Espárragos
if (pH >= 6.0 && pH <= 7.0 && temperature >= 18 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de espárragos");
}
// Sandías
if (pH >= 5.5 && pH <= 6.5 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de sandías");
}
// Melones
if (pH >= 6.0 && pH <= 7.0 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de melones");
}
// Limones
if (pH >= 5.5 && pH <= 6.5 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    Serial.println("Recomendar siembra de limones");
}
// Naranjas
if (pH >= 6.0 && pH <= 7.0 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de naranjas");
}
// Peras
if (pH >= 5.5 && pH <= 6.5 && temperature >= 15 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    Serial.println("Recomendar siembra de peras");
}
// Duraznos
if (pH >= 6.0 && pH <= 7.0 && temperature >= 15 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de duraznos");
}
// Albaricoques
if (pH >= 5.5 && pH <= 6.5 && temperature >= 15 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    Serial.println("Recomendar siembra de albaricoques");
}
// Ciruelas
if (pH >= 6.0 && pH <= 7.0 && temperature >= 15 && temperature <= 25 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de ciruelas");
}
// Mangos
if (pH >= 5.5 && pH <= 6.5 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 950 && pressure <= 1020) {
    Serial.println("Recomendar siembra de mangos");
}
// Piñas
if (pH >= 6.0 && pH <= 7.0 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de piñas");
}
// Pimientos
if (pH >= 5.5 && pH <= 6.5 && temperature >= 20 && temperature <= 30 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de pimientos");
}
// Calabazas
if (pH >= 6.0 && pH <= 7.0 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de calabazas");
}
// Espinacas
if (pH >= 5.5 && pH <= 6.5 && temperature >= 15 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de espinacas");
}
// Pepinos
if (pH >= 6.0 && pH <= 7.0 && temperature >= 25 && temperature <= 35 && humidity >= 60 && humidity <= 80 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de pepinos");
}
// Repollos
if (pH >= 5.5 && pH <= 6.5 && temperature >= 18 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de repollos");
}
// Brócoli
if (pH >= 6.0 && pH <= 7.0 && temperature >= 18 && temperature <= 25 && humidity >= 70 && humidity <= 90 && pressure >= 980 && pressure <= 1020) {
    Serial.println("Recomendar siembra de brócoli");
  }
else {
  Serial.println("No recomendar siembra aún");
  }
}
  /*Agregamos un delay de 10 segundos para el envío, y que luego de este tiempo, se proceda a reiniciar el bucle*/
  delay(10000); 
  ubidots.loop();
}
