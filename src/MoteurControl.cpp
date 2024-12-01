//MoteurControl.cpp
#include "../include/MoteurControl.h"
#include <AccelStepper.h>
#include <Arduino.h>
#include "../include/Config.h" 


// Initialisation du moteur
AccelStepper motor1(1, STEP_PIN, DIR_PIN);

void initMotorControl() {
  pinMode(MS1_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  digitalWrite(MS1_PIN, HIGH);
  digitalWrite(MS2_PIN, HIGH);
  digitalWrite(ENABLE_PIN, LOW);

  motor1.setMaxSpeed(MAX_SPEED);
  motor1.setAcceleration(ACCELERATION);
  motor1.setSpeed(MOTOR_SPEED);
}

void controlMotor() {
  motor1.setSpeed(1200);
  motor1.runSpeed();
}
