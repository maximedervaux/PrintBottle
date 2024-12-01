#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "./include/TemperatureControl.h"
#include "./include/MoteurControl.h"
#include "./include/Config.h"

// Variables pour les intervalles
unsigned long previousTemperatureMillis = 0;
unsigned long previousPrintMillis = 0;

void setup() {
  Serial.begin(9600);
  // Initialiser les modules
  initTemperatureControl();
  initMotorControl();
}

void loop() {
  unsigned long currentMillis = millis();

  // Mettre à jour la température seulement toutes les 100 ms
  if (currentMillis - previousTemperatureMillis >= TEMPERATURE_INTERVAL) {
    previousTemperatureMillis = currentMillis;
    controlTemperature();  
  }

  // Afficher les informations de la buse toutes les 1 seconde
  if (currentMillis - previousPrintMillis >= PRINT_INTERVAL) {
    previousPrintMillis = currentMillis;
    printBuseInfos(); 
  }

  // Gérer le moteur sans interruption
  controlMotor();
}