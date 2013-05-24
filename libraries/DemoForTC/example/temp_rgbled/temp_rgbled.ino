// demo of temperature -> rgbLED
// temperature form 25 - 32,  rgbLed  from green -> red
// Grove-temperature plu to A0
// LED plug to D7,D8

#include <Streaming.h>
#include <ChainableLED.h>

#define TEMPUP      32
#define TEMPDOWN    25

ChainableLED leds(7, 8, 1);                                     // connect to pin7 and pin8 , one led

int getAnalog()                                                 // get value from A0
{
    int sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(A0);
    }
    
    return sum>>5;
}

float getTemp()                                                 // get temperature
{
    float temperature = 0.0;
    float resistance  = 0.0;
    int B = 3975;                                               //B value of the thermistor
    
    int a = getAnalog();
    
    resistance  = (float)(1023-a)*10000/a;                      //get the resistance of the sensor;
    temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15;  //convert to temperature via datasheet ;
    return temperature;
}

void ledLight(int dta)                                          // light led
{

    dta = dta/4;        // 0 - 255
    
    int colorR = dta;
    int colorG = 255-dta;
    int colorB = 0;

    leds.setColorRGB(0, colorR, colorG, colorB);
}

void setup()
{
    Serial.begin(38400);
    cout << "hello world !" << endl;
}

void loop()
{
    float temp = getTemp();
    int nTemp  = temp*100;
    
    nTemp = nTemp > TEMPUP*100 ? TEMPUP*100 : (nTemp < TEMPDOWN*100 ? TEMPDOWN*100 : nTemp);
    nTemp = map(nTemp, TEMPDOWN*100, TEMPUP*100, 0, 1023);
    ledLight(nTemp);
    delay(100);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/