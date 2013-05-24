/*
  demo of fade_led
  .
  led plug to D13
*/

#include <SoftPWM.h>

int pinLed  = 13;

void setup()
{
    SoftPWMBegin();                         // Sets the PWM value to 0 for the built-in LED (pinLed).
        
    SoftPWMSet(pinLed, 0);
    
    SoftPWMSetFadeTime(pinLed, 1000, 1000); // Sets the default fade time for pinLed to
                                            // 100 ms fade-up and 550 ms to fade-down.
}

void loop()
{
    
    SoftPWMSet(pinLed, 255);                // Turn on pinLed
    delay(1200);                            // Wait for the fade-up and some extra delay.  
    SoftPWMSet(pinLed, 0);                  // Turn off pinLed
    delay(1200);                            // Wait for the fade-down, and some extra delay.
}


/*********************************************************************************************************
  END FILE
*********************************************************************************************************/