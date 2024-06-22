/*
 * Ce code est conçu pour surveiller les émissions des véhicules en utilisant des capteurs de gaz et de particules,
 * un microcontrôleur ESP32, et une communication via Wi-Fi.
 * Il collecte, envoie et affiche les données de pollution en temps réel.
 * 
 * Auteur : Saynbe Mo
 * Copyright (c) 2024 Saynbe Mo
 * Tous droits réservés.
 * Ce code peut être utilisé par Orange Cameroun.
 */


#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_Sensor.h> 
#include <MQ135.h>//librairie pour le capteur MQ135
// INFO du point d'acces pour la transmission des donnees
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Adresse du serveur pour envoyer les données
const char* serverName = "http://your_server_endpoint";

// Initialiser les capteurs
MQ135 mq135 = MQ135(A0);


void setup() {
  Serial.begin(115200);

  // Connexion au Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  }

void loop() {
  // Lire les données des capteurs
  float co2 = mq135.getPPM();


  // Envoyer les données au serveur
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String httpRequestData = "co2=" + String(co2);
    int httpResponseCode = http.POST(httpRequestData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }

  delay(60000); // Attendre 1 minute avant de lire les capteurs à nouveau
}
