//TemperatureControl.cpp
#include "../include/TemperatureControl.h"
#include <Arduino.h>
#include <Wire.h>
#include "../include/Config.h" 


float voltage;
float therm_resistance;
float temperature;
float consigne;


void initTemperatureControl() {
  pinMode(MOSFET_PIN, OUTPUT);
}



void printBuseInfos() {
  Serial.print("Tension : ");
  Serial.print(voltage, 2);
  Serial.print(" V | Résistance thermistance : ");
  Serial.print(therm_resistance, 2);
  Serial.print(" Ohm | Température : ");
  Serial.print(temperature);
  Serial.print(" °C | Consigne : ");
  Serial.println(consigne, 2);
}

void controlTemperature() {
  int reading = analogRead(THERMISTOR_PIN);
  voltage = reading * (5.0 / 1023.0);
  therm_resistance = REFERENCE_RESISTANCE * (voltage / (5.0 - voltage));
  temperature = 1.0 / (1.0 / 293.15 + 1.0 / 4050.0 * log(therm_resistance / THERMISTOR_RESISTANCE_20C)) - 273.15;
  
  int reading_REGUL_PIN  = analogRead(REGUL_PIN );
  consigne = reading_REGUL_PIN  * (250.0 / 1023.0);

  if (temperature < consigne) {
    analogWrite(MOSFET_PIN, 150);
  } else {
    analogWrite(MOSFET_PIN, 0);
  }

   

}
