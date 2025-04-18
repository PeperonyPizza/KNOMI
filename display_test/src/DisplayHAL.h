#pragma once
#include <TFT_eSPI.h>

class DisplayHAL {
public:
    TFT_eSPI *tft;
    int currentPattern = 0;
    const int patternCount = 6;  // Number of test patterns

    DisplayHAL() {
        Serial.println("Initializing TFT display...");
        
        // Initialize SPI pins first
        pinMode(TFT_CS, OUTPUT);
        digitalWrite(TFT_CS, HIGH);
        delay(10);
        
        pinMode(TFT_DC, OUTPUT);
        digitalWrite(TFT_DC, HIGH);
        delay(10);
        
        pinMode(TFT_RST, OUTPUT);
        digitalWrite(TFT_RST, HIGH);
        delay(10);
        
        pinMode(TFT_BL, OUTPUT);
        digitalWrite(TFT_BL, HIGH);
        delay(10);
        
        // Reset sequence
        digitalWrite(TFT_RST, LOW);
        delay(50);
        digitalWrite(TFT_RST, HIGH);
        delay(50);
        
        // Create and initialize TFT
        tft = new TFT_eSPI(TFT_WIDTH, TFT_HEIGHT);
        tft->init();
        delay(100);
        
        // Configure display
        tft->setRotation(0);
        tft->invertDisplay(true);
        tft->fillScreen(TFT_BLACK);
        delay(100);
        
        // Set text parameters
        tft->setTextColor(TFT_WHITE, TFT_BLACK);
        tft->setTextSize(4);  // Large text size
        tft->setTextDatum(MC_DATUM);
        tft->setTextWrap(true);
        
        Serial.println("Display initialization complete");
    }

    void setBackgroundColor(uint32_t color) { 
        tft->fillScreen(toSpiColor(color)); 
    }

    void drawNextPattern() {
        Serial.print("Drawing pattern ");
        Serial.println(currentPattern);
        
        tft->startWrite();
        
        switch(currentPattern) {
            case 0:  // Solid black
                tft->fillScreen(TFT_BLACK);
                Serial.println("Pattern 0: Black screen");
                break;
                
            case 1:  // Solid white
                tft->fillScreen(TFT_WHITE);
                Serial.println("Pattern 1: White screen");
                break;
                
            case 2:  // Checkerboard
                drawCheckerboard();
                Serial.println("Pattern 2: Checkerboard");
                break;
                
            case 3:  // Gradient
                drawGradient();
                Serial.println("Pattern 3: Gradient");
                break;
                
            case 4:  // Concentric circles
                drawConcentricCircles();
                Serial.println("Pattern 4: Concentric circles");
                break;
                
            case 5:  // Color bars
                drawColorBars();
                Serial.println("Pattern 5: Color bars");
                break;
        }
        
        tft->endWrite();
        
        // Move to next pattern
        currentPattern = (currentPattern + 1) % patternCount;
    }

    void drawCheckerboard() {
        int squareSize = 20;
        bool color = true;
        
        for(int y = 0; y < TFT_HEIGHT; y += squareSize) {
            for(int x = 0; x < TFT_WIDTH; x += squareSize) {
                tft->fillRect(x, y, squareSize, squareSize, color ? TFT_WHITE : TFT_BLACK);
                color = !color;
            }
            color = !color;
        }
    }

    void drawGradient() {
        for(int y = 0; y < TFT_HEIGHT; y++) {
            uint16_t color = tft->color565(y, y, y);
            tft->drawFastHLine(0, y, TFT_WIDTH, color);
        }
    }

    void drawConcentricCircles() {
        tft->fillScreen(TFT_BLACK);
        int centerX = TFT_WIDTH / 2;
        int centerY = TFT_HEIGHT / 2;
        
        for(int r = 5; r < TFT_WIDTH/2; r += 10) {
            uint16_t color = tft->color565(r, r, r);
            tft->drawCircle(centerX, centerY, r, color);
        }
    }

    void drawColorBars() {
        int barWidth = TFT_WIDTH / 6;
        uint16_t colors[] = {TFT_RED, TFT_GREEN, TFT_BLUE, TFT_YELLOW, TFT_CYAN, TFT_MAGENTA};
        
        for(int i = 0; i < 6; i++) {
            tft->fillRect(i * barWidth, 0, barWidth, TFT_HEIGHT, colors[i]);
        }
    }

    static uint32_t toSpiColor(uint32_t color) {
        byte r = color >> 16 & 0xFF;
        byte g = color >> 8 & 0xFF;
        byte b = color >> 0 & 0xFF;
        return ((r & 0xF8) << 8 | (g & 0xFC) << 3 | (b >> 3));
    }
}; 