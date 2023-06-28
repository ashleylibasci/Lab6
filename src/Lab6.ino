SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
#include "oled-wing-adafruit.h"

OledWingAdafruit display;

void setup()
{
  display.setup();
  display.clearDisplay();
  display.display(); // cause the display to be updated
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hello, world!");
  display.display();
}

void loop()
{
}