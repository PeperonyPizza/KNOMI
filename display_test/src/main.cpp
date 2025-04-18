#include <Arduino.h>
#include "DisplayHAL.h"
#include "tft_setup.h"

DisplayHAL* display = nullptr;

void setup() {
    Serial.begin(115200);
    Serial.println("\n\n=== Display Test Starting ===");
    
    // Wait for serial to be ready
    while (!Serial) {
        delay(10);
    }
    Serial.println("Serial port ready");
    
    // Create and initialize display
    Serial.println("Creating DisplayHAL object...");
    display = new DisplayHAL();
    Serial.println("DisplayHAL object created");
    
    delay(500);  // Give display time to stabilize
    Serial.println("Display stabilized, starting test patterns...");
}

void loop() {
    // Draw the next pattern and wait
    display->drawNextPattern();
    delay(2000);  // Show each pattern for 2 seconds
} 