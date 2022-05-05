/*
    Code for a electronic dice based on Arduino Nano
    Code designed by Eingel
    Ig: @angelinho___
*/
#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 7
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN        5
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int n; //random number
int delayval = 500;//delay time
int button = 8; //button time
int red; //value of the red color
int green; //value of the green color
int blue; //value of the blue color
int buzzer = 6; //buzzer pin
int sounf = 200; //buzzer frequency

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pinMode(button, INPUT);
  pixels.begin();
  pinMode (buzzer, OUTPUT);
}

void loop() {
  setcolor(); //function to create a random rgb value
  pixels.clear();//turn off all pixels
  if (digitalRead(button) == 1) {
    n = random(1, 7); //function to create a random number between 1 and 6
    if (n == 1) {
      one(); //function to represent the number one
    }
    if (n == 2) {
      two();  //function to represent the number two
    }
    if (n == 3) {
      three();//function to represent the number three
    }
    if (n == 4) {
      four();//function to represent the number four
    }
    if (n == 5) {
      five();//function to represent the number five
    }
    if (n == 6) {
      six();//function to represent the number six
    }
  }
}

void setcolor() { //random rgb values
  red = random(0, 255);
  green = random(0, 255);
  blue = random(0, 255);
}

void one() {
  pixels.setPixelColor(3, pixels.Color(red, green, blue));
  pixels.show(); //function to show lit pixels
  for (int i = 0; i < 1; i++) {
    tone(buzzer, sounf);
    delay(delayval);
    noTone (buzzer);
    delay(delayval);
  }
}

void two() {
  pixels.setPixelColor(0, pixels.Color(red, green, blue)); //function to select color the pin of each pixel
  pixels.setPixelColor(6, pixels.Color(red, green, blue));
  pixels.show();
  for (int i = 0; i < 2; i++) {
    tone(buzzer, sounf);
    delay(delayval);
    noTone (buzzer);
    delay(delayval);
  }
}
void three() {
  pixels.setPixelColor(0, pixels.Color(red, green, blue));
  pixels.setPixelColor(3, pixels.Color(red, green, blue));
  pixels.setPixelColor(6, pixels.Color(red, green, blue));
  pixels.show();
  for (int i = 0; i < 3; i++) {
    tone(buzzer, sounf);
    delay(delayval);
    noTone (buzzer);
    delay(delayval);
  }
}
void four() {
  pixels.setPixelColor(0, pixels.Color(red, green, blue));
  pixels.setPixelColor(2, pixels.Color(red, green, blue));
  pixels.setPixelColor(4, pixels.Color(red, green, blue));
  pixels.setPixelColor(6, pixels.Color(red, green, blue));
  pixels.show();
  for (int i = 0; i < 4; i++) {
    tone(buzzer, sounf);
    delay(delayval);
    noTone (buzzer);
    delay(delayval);
  }
}
void five() {
  pixels.setPixelColor(0, pixels.Color(red, green, blue));
  pixels.setPixelColor(2, pixels.Color(red, green, blue));
  pixels.setPixelColor(3, pixels.Color(red, green, blue));
  pixels.setPixelColor(4, pixels.Color(red, green, blue));
  pixels.setPixelColor(6, pixels.Color(red, green, blue));
  pixels.show();
  for (int i = 0; i < 5; i++) {
    tone(buzzer, sounf);
    delay(delayval);
    noTone (buzzer);
    delay(delayval);
  }
}
void six() {
  pixels.setPixelColor(0, pixels.Color(red, green, blue));
  pixels.setPixelColor(1, pixels.Color(red, green, blue));
  pixels.setPixelColor(2, pixels.Color(red, green, blue));
  pixels.setPixelColor(4, pixels.Color(red, green, blue));
  pixels.setPixelColor(5, pixels.Color(red, green, blue));
  pixels.setPixelColor(6, pixels.Color(red, green, blue));
  pixels.show();
  for (int i = 0; i < 6; i++) {
    tone(buzzer, sounf);
    delay(delayval);
    noTone (buzzer);
    delay(delayval);
  }
}
