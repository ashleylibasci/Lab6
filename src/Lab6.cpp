/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/ashleylibasci/IoTFolderLabs/Lab6/src/Lab6.ino"
#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 3 "/Users/ashleylibasci/IoTFolderLabs/Lab6/src/Lab6.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void setup()
{
  pinMode(A4, INPUT);

  display.setup();
  display.clearDisplay();
  display.display(); // cause the display to be updated
}

void loop()
{
  uint64_t reading = analogRead(A4);
  double voltage = (reading * 3.3) / 4095.0;
  double temperature = (voltage - 0.5) * 100;

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(temperature);
  display.setCursor(37, 0);
  display.println("degrees celsius");
  display.display();
}