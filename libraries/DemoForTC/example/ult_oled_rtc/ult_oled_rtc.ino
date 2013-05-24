// demo of ...ultrasonic & oled & RTC
// oled plug to I2C port
// OLED plug to I2C port
// ultarsonic plug to D7

#include <Streaming.h>
#include <Wire.h>
#include <SeeedGrayOLED.h>
#include <Ultrasonic.h>
#include <DS1307.h>

Ultrasonic ultrasonic1(7);                  // define a object of Ultrasonic

DS1307 clock;                               // define a object of DS1307 class

void initOled()
{
    Wire.begin();
    SeeedGrayOled.init();                   //initialize SEEED OLED display
    SeeedGrayOled.clearDisplay();           //Clear Display.
    SeeedGrayOled.setNormalDisplay();       //Set Normal Display Mode
    SeeedGrayOled.setVerticalMode();        // Set to vertical mode for displaying text
}

void printUltra()
{
    int dist = 0;
    char sUltra[30];

    ultrasonic1.MeasureInCentimeters();

    dist = ultrasonic1.RangeInCentimeters;
    sprintf(sUltra, "%4d cm", dist);

    SeeedGrayOled.setTextXY(6, 2);          //set Cursor to ith line, 0th column
    SeeedGrayOled.putString(sUltra);        //Print Hello World
}

void printTime()
{
    char stime[30];
    clock.getTime();
    sprintf(stime, "%2d:%2d:%2d", clock.hour, clock.minute, clock.second);

    SeeedGrayOled.setTextXY(3,1);           //set Cursor to ith line, 0th column
    SeeedGrayOled.putString(stime);         //Print Hello World
}

void setup()
{
    Serial.begin(38400);
    clock.begin();
    initOled();
    cout << "init over!" << endl;
}

void loop()
{
    printTime();                            // print time on OLED
    printUltra();                           // print distance on OLED
    delay(100);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/