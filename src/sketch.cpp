/* Blink example from Arduino lib. See readme for info about using this in Eclipse.
*/
#include <Arduino.h>

void setup()
{
    // initialize the digital pin as an output.
    // Pin 13 has an LED connected on most Arduino boards:
    pinMode(13, OUTPUT);
}

void loop()
{
    digitalWrite(13, HIGH);   // set the LED on
    delay(200);              // wait for a second
    digitalWrite(13, LOW);    // set the LED off
    delay(200);              // wait for a second
}
