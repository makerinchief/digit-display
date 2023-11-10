#include <FastLED.h>
#include "colors.h"

void setup() {
  
  Serial.begin(115200);
  
  led_init();

  set_number(0, white);
  led_update();
  delay(2000);
  set_number(1, red);
  led_update();
  delay(2000);
  set_number(2, green);
  led_update();
  delay(2000);
  set_number(3, blue);
  led_update();
  delay(2000);
  set_number(4, magenta);
  led_update();
  delay(2000);
  set_number(5, yellow);
  led_update();
  delay(2000);
  set_number(6, cyan);
  led_update();
  delay(2000);
  set_number(7, orange);
  led_update();
  delay(2000);
  set_number(8, light_green);
  led_update();
  delay(2000);
  set_number(9, light_blue);
  led_update();
  delay(2000);
  set_number(0, off);
  led_update();
  delay(2000);
  
}

void loop() {
}
