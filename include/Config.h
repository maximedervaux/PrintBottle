// config.h
#ifndef CONFIG_H
#define CONFIG_H

// Définition des broches
#define THERMISTOR_PIN    A0           // Broche pour la thermistance
#define MOSFET_PIN        9            // Broche pour le MOSFET
#define REGUL_PIN         A1           // Broche pour la régulation
#define STEP_PIN          2            // Broche pour le moteur (step)
#define DIR_PIN           3            // Broche pour le moteur (direction)
#define ENABLE_PIN        4            // Broche pour activer/désactiver le moteur
#define MS1_PIN           5            // Broche pour le micro-pas du moteur
#define MS2_PIN           6            // Broche pour le micro-pas du moteur


// Paramètres moteur
#define MAX_SPEED           1000       // Vitesse maximale du moteur
#define ACCELERATION        500        // Accélération du moteur
#define MOTOR_SPEED         1200       // Vitesse de rotation du moteur (en pas/s)


// Paramètres partie chauffe
#define TEMPERATURE_INTERVAL 100 // Millisecond
#define REFERENCE_RESISTANCE  10000.0f
#define THERMISTOR_RESISTANCE_20C 115000.0f



// Temps de print 
#define PRINT_INTERVAL 1000


#endif // CONFIG_H


