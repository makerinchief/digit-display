#include <FastLED.h>

//PWM Pin to control LEDs
const int LED_PIN = 9;

//Number of leds in each segment
const int LEDS_PER_SEGMENT = 3;

//Number of segments in a digit
const int SEGMENT_COUNT = 7;

//Number of leds for a digit
const int LED_COUNT = SEGMENT_COUNT * LEDS_PER_SEGMENT;

//Then all the leds can be represented by a grid of numbers
int digit_segments[SEGMENT_COUNT][LEDS_PER_SEGMENT] = {0};

CRGB leds[LED_COUNT];
byte leds_brightness = 100;

void led_update() {
  FastLED.show();
}

void led_init() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
  FastLED.setBrightness(50);
  led_init_grid();
}

void led_init_grid() {

  int led_num = 0;

  for (int i = 0; i < SEGMENT_COUNT; i++) {
    for (int j = 0; j < LEDS_PER_SEGMENT; j ++ ) {
      digit_segments[i][j] = led_num;
      led_num += 1;
    }
  }

}

void set_all_leds(CRGB color) {
  for (int i = 0; i < LED_COUNT; i++) {
    leds[i] = color;
  }
}

void set_led_color(int num, CRGB color ) {
  leds[num] = color;
}

void set_segment_color(int segment, CRGB color) {
  for (int i = 0; i < LEDS_PER_SEGMENT; i++) {
    int led_num_ = digit_segments[segment][i];
    leds[led_num_] = color;
  }
}

void set_number(byte number, CRGB color) {
  
  byte segments = get_segments(number);
  int digit_place = 0;
  
  for (byte i = 0; i < SEGMENT_COUNT; i++) {
    
    byte segment_num = i + SEGMENT_COUNT * digit_place;
    byte segment_val = 1 << (SEGMENT_COUNT - i);
    bool segment_on = segments & segment_val;
    
    if (segment_on) {
      set_segment_color(segment_num, color);
    } else {
      set_segment_color(segment_num, off);
    }
  }
}

void run_test() {
  set_all_leds(CRGB(255, 255, 255));
  FastLED.show();
  delay(2000);

  set_all_leds(CRGB(0, 0, 0));
  FastLED.show();
  delay(2000);

  for (int i = 0; i < SEGMENT_COUNT; i++) {
    set_segment_color(i, CRGB(255, 255, 255));
    FastLED.show();
    delay(250);
  }
}

/*
  Get the segements needed to display a number 0 - 9

  Segments are arranged like below:

    --b--
   |     |
  a|     |c
   |     |
    --d--
   |     |
  e|     |g
   |     |
    --f--

  We can represent the segments needed to represent a number
  with a byte where each bit represenets a segment.

  byte segments => [ a, b, c, d, e, f, g, 0 ]

   And can represented by a byte like this:

   The number 1 would have segments 'c' and 'g' on
   and the rest off.

   So '1' can be represented as
   '1' => 0010001

*/

// Get the segments needed to display a number 0 - 9
byte get_segments(byte number) {

  byte a = 1 << 7;
  byte b = 1 << 6;
  byte c = 1 << 5;
  byte d = 1 << 4;
  byte e = 1 << 3;
  byte f = 1 << 2;
  byte g = 1 << 1;

  byte segments = 0;

  switch (number) {

    case 0:
      segments = a | b | c | e | f | g;
      break;

    case 1:
      segments = c | g;
      break;

    case 2:
      segments =  b | c | d | e | f;
      break;

    case 3:
      segments = b | c | d | f | g;
      break;

    case 4:
      segments = a | c | d | g;
      break;

    case 5:
      segments = a | b | d | f | g;
      break;

    case 6:
      segments =  a | b | d | e | f | g;
      break;

    case 7:
      segments = b | c | g;
      break;

    case 8:
      segments = a | b | c | d | e | f | g;
      break;

    case 9:
      segments = a | b | c | d | g;
      break;

    default:
      break;
  }

  return segments;

}
