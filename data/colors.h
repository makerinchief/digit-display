#include <FastLED.h>

CRGB led_colors[LED_COUNT];

CRGB colors[] = {CRGB(255, 0, 0),
                 CRGB(0, 255, 0),
                 CRGB(0, 0, 255),
                 CRGB(255, 255, 0),
                 CRGB(255, 0, 255),
                 CRGB(0, 255, 255),
                 CRGB(255, 255, 255),
                 CRGB(180, 100, 0),
                 CRGB(100, 100, 0),
                 CRGB(180, 100, 180),
                };

CRGB white = CRGB(255, 255, 255);
CRGB red = CRGB(255, 0, 0);
CRGB green = CRGB(0, 255, 0);
CRGB blue = CRGB(0, 0, 255);
CRGB cyan = CRGB(0, 255, 255);
CRGB off = CRGB(0, 0, 0);
