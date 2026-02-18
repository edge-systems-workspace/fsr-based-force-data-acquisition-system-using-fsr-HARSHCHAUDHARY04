#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Force Measurement System using FSR
 * @author HARSH CHAUDHARY
 * @date 2026-02-18
 *
 * @details
 * This program reads analog force data from a Force Sensitive Resistor (FSR) sensor
 * and displays the measurements via Serial Monitor.
 * 
 * HOW IT WORKS:
 * - The FSR changes resistance based on applied force
 * - A voltage divider (FSR + 10kΩ resistor) converts this to a measurable voltage
 * - The Arduino ADC reads this voltage as a value between 0-1023
 * - When force is applied, the ADC value increases
 * - The program displays these values and detects when pressure exceeds a threshold
 * 
 * HARDWARE SETUP:
 * - FSR Sensor connected to 5V power supply
 * - FSR Sensor also connected to Arduino Analog Pin A0
 * - 10kΩ Resistor connected between A0 and Ground (GND)
 * - This creates a voltage divider that lets us measure the FSR resistance
 */

// ===== PIN CONFIGURATION =====
// TODO 1: Define FSR analog pin (Use A0)
// A0 is the analog input pin where our FSR voltage signal comes in
const int FSR_PIN = A0;

// ===== SENSOR VARIABLES =====
// TODO 2: Create variable to store sensor reading
// This will hold the raw ADC value (0-1023) from the FSR sensor
int sensorReading = 0;

// ===== THRESHOLD SETTINGS =====
// Threshold value for pressure detection
// When ADC value exceeds this, we consider it as "pressure detected"
// Adjust this value based on your FSR sensitivity requirements
const int PRESSURE_THRESHOLD = 100;

/**
 * @brief Initializes the system and serial communication
 * 
 * This function runs once when the Arduino starts up.
 * It sets up Serial communication so we can see sensor readings
 * on the computer via USB connection.
 * 
 * @return void
 */
void setup() {
    // TODO 3: Initialize Serial communication (9600 baud rate)
    // 9600 baud rate is a standard speed for Arduino communication
    // This allows us to send/receive data at 9600 bits per second
    Serial.begin(9600);
    
    // TODO 4: Print system initialization message
    // Display welcome message so user knows system is ready
    Serial.println("================================");
    Serial.println("   FSR Force Measurement System");
    Serial.println("  System Initialized Successfully!");
    Serial.println("================================");
    Serial.println("Reading FSR Values...");
    Serial.println();
    
    // Wait a bit to ensure serial port is fully initialized
    // This prevents any data loss at startup
    delay(1000);
}

/**
 * @brief Main program loop for continuous sensor monitoring
 * 
 * This function runs repeatedly in a loop (forever) once setup() completes.
 * It continuously:
 * - Reads the current analog value from the FSR sensor
 * - Compares it against our pressure threshold
 * - Displays human-readable measurements on the Serial Monitor
 * 
 * @return void
 */
void loop() {
    // TODO 5: Read analog value from FSR
    // analogRead() measures the voltage at pin A0 and converts it to a number 0-1023
    // 0 means no voltage (no force on FSR)
    // 1023 means full 5V (maximum force on FSR)
    sensorReading = analogRead(FSR_PIN);
    
    // TODO 6: Print raw ADC value
    // Display the raw measurement so user can see actual sensor values
    Serial.print("Raw ADC Value: ");
    Serial.print(sensorReading);
    Serial.print(" | ");
    
    // TODO 7: Apply simple threshold logic (e.g., detect pressure)
    // Compare the sensor reading against our threshold
    // This helps us determine if significant force is being applied
    if (sensorReading > PRESSURE_THRESHOLD) {
        // TODO 8: Print pressure detection message
        // If force is detected, show this message
        Serial.println("Status: ⚡ PRESSURE DETECTED");
    } else {
        // If no significant force, show idle status
        Serial.println("Status: ✓ No Pressure (Idle)");
    }
    
    // TODO 9: Add delay (500ms or 1 second)
    // Wait 1 second before taking the next reading
    // This prevents the output from being too fast and unreadable
    // Adjust this if you want faster or slower readings
    delay(1000);
}
