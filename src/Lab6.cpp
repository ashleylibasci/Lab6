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
  double celsius = (voltage - 0.5) * 100;

  double farenheit = (celsius * 9 / 5) + 32;

  display.loop();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(celsius);
  display.setCursor(33, 0);
  display.println("degrees celsius");

  display.setCursor(0, 15);
  display.println(farenheit);
  display.setCursor(32, 15);
  display.println("degrees");
  display.setCursor(74.5, 15);
  display.println("farenheit");

  display.display();
}