#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

uint64_t reading = analogRead(A4);
double voltage = (reading * 3.3) / 4095.0;
double celsius = (voltage - 0.5) * 100;
double farenheit = (celsius * 9.0 / 5.0) + 32.0;

void setup()
{
  pinMode(A4, INPUT);

  display.setup();
  display.clearDisplay();
  display.display(); // cause the display to be updated
}

void loop()
{
  celsiusFunction;
  farenheitFunction;
}

void celsiusFunction()
{
  display.clearDisplay(); // make the 2 blocks of code functions in like void loop to make it simpler
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(celsius);
  display.setCursor(33, 0);
  display.println("degrees celsius");
  display.display();
}

void farenheitFunction()
{
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 15);
  display.println(farenheit);
  display.setCursor(32, 15);
  display.println("degrees");
  display.setCursor(74.5, 15);
  display.println("farenheit");
  display.display();
}
