#ifndef TFT_SETUP_H
#define TFT_SETUP_H

#define USER_SETUP_LOADED
#define DISABLE_ALL_LIBRARY_WARNINGS

// Workaround for ESP32 SPI port issue
#define USE_HSPI_PORT

// See SetupX_Template.h for all options available
#define USER_SETUP_ID 46

#define TFT_RGB_ORDER TFT_RGB

#define GC9A01_DRIVER
#define TFT_WIDTH 240
#define TFT_HEIGHT 240

// Pin configuration from original project
#define TFT_MOSI 23  // MOSI pin
#define TFT_SCLK 18  // SCLK pin
#define TFT_CS   5   // Chip select pin
#define TFT_DC   19  // Data/Command pin
#define TFT_RST  4   // Reset pin
#define TFT_BL   2   // Backlight pin

// Font settings
#define LOAD_GLCD
#define LOAD_GFXFF
#define SMOOTH_FONT

// SPI settings
#define SPI_FREQUENCY 27000000
#define SPI_READ_FREQUENCY 20000000

// Display settings
#define TFT_INVERSION_ON  // Enable display inversion
#define TFT_BLACK 0x0000
#define TFT_WHITE 0xFFFF

// Define center points for circular display
#define CENTER_X (TFT_WIDTH / 2)
#define CENTER_Y (TFT_HEIGHT / 2)

#endif 