#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Force Measurement System using FSR
 * @author Harsh Chaudhary
 * @date 2026-02-19
 *
 * @details
 * This program reads analog force data from a Force Sensitive Resistor (FSR) sensor
 * and displays the measurements via Serial Monitor.
 */

const int FSR_PIN = A0;

int sensorReading = 0;

const int PRESSURE_THRESHOLD = 100;

void setup() {
    Serial.begin(9600);
    Serial.println("FSR Force Measurement System Initialized");
    delay(1000);
}

void loop() {
    sensorReading = analogRead(FSR_PIN);

    Serial.print("Raw ADC Value: ");
    Serial.print(sensorReading);
    Serial.print(" | ");

    if (sensorReading > PRESSURE_THRESHOLD) {
        Serial.println("Status: ⚡ PRESSURE DETECTED");
    } else {
        Serial.println("Status: ✓ No Pressure (Idle)");
    }

    delay(1000);
}
