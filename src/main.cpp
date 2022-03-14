#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// for USB and other build flags: https://docs.platformio.org/en/latest/platforms/teensy.html

// GUItool: begin automatically generated code
AudioInputUSB            usb_in;           //xy=352.00000381469727,464.0000057220459
AudioAmplifier           amp_R;           //xy=499.00000762939453,484.00000762939453
AudioAmplifier           amp_L;           //xy=500,447
AudioOutputMQS           mqs_out;           //xy=654.0000076293945,465.0000066757202
AudioConnection          patchCord1(usb_in, 0, amp_L, 0);
AudioConnection          patchCord2(usb_in, 1, amp_R, 0);
AudioConnection          patchCord3(amp_R, 0, mqs_out, 1);
AudioConnection          patchCord4(amp_L, 0, mqs_out, 0);
// GUItool: end automatically generated code

float32_t volume = 0;

void setup() {
    AudioMemory(20);
    amp_L.gain(volume);
    amp_R.gain(volume);
    delay(500);
}

void loop() {
    // Only update on change
    if(usb_in.features.change == 1) {
        volume = usb_in.volume();
        amp_L.gain(volume);
        amp_R.gain(volume);

        usb_in.features.change = 0;
    }
    
}