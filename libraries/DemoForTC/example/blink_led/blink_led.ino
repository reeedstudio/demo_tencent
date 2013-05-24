/*
  demo of led blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  
  led plug to D13
*/

int led = 13;

void setup() 
{
    pinMode(led, OUTPUT);                   // initialize the digital pin as an output.
}

void loop() 
{
    digitalWrite(led, HIGH);                // turn the LED on (HIGH is the voltage level)
    delay(1000);                            // wait for a second
    digitalWrite(led, LOW);                 // turn the LED off by making the voltage LOW
    delay(1000);                            // wait for a second
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/