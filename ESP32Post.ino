#include <WiFi.h>
#include <HTTPClient.h> // nos permite hacer peticiones http
#include <ArduinoJson.h>
#include "DHT.h"

//DHT22
#define pinDatos 33  //GPIO4 = D2 en D1 Mini, D4 en ESP32
DHT sensorTH (pinDatos, DHT22);    //Crea objeto sensorTH

//MQ135
int s_analogica_mq135=12;

// Credenciales wifi
#define WIFI_SSID "Diego"
#define WIFI_PASSWORD "1234567890"
//const char* ssid = "Tenda_3DE948";
//const char* password = "18264838";
//IPAddress ip(192,168,10,9);     
//IPAddress gateway(192,168,10,1);   
//IPAddress subnet(255,255,255,0);   
//Temperatura


void setup() {
    Serial.begin(115200);
     sensorTH.begin ();   //Inicializa pines del sensor

    // conexión a la red
  //    WiFi.mode(WIFI_STA);
    //  WiFi.config(ip, gateway, subnet);
      WiFi.begin(ssid, password);
//    IPAddress ip(192,168,10,145);     
//    IPAddress gateway(192,168,10,1);   
//    IPAddress subnet(255,255,255,0);   
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
    }
    Serial.println("");
    Serial.print("Conectado a la red con la IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

}

void loop() {
  if(WiFi.status()== WL_CONNECTED ){ 
 //se agregan valores al documento
DynamicJsonDocument doc(2048);

  doc["dioxido"] =  analogRead(s_analogica_mq135);
  doc["humedad"] = sensorTH.readHumidity();
  doc["temperatura"] = sensorTH.readTemperature();
  

// documento serializado
String json;
serializeJson(doc, json);

WiFiClient client;  // or WiFiClientSecure for HTTPS
HTTPClient http;
// Send request
http.begin("https://https://invernadero.onrender.com/insertar");
//cabeceras JSON
http.addHeader("Content-Type", "application/json");
int res = http.POST(json);

Serial.println(json);
// respuesta
Serial.println(http.getString());
Serial.println(res);
// desconecta
http.end();
delay(30000);
}
}