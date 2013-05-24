// demo of Rotary to control a servo
// servo plug to D9
// Rotary plug to A0

#include <Streaming.h>
#include <Servo.h> 

Servo myservo;                          // create servo object to control a servo 

int posServo    = 0;
int posServoBuf = 0;

int getAnalog()                         // get data of A0
{

    int sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(A0);
    }
    
    return sum>>5;
}

void servoPos(int pos)                  // set servo positon, 0-180
{

    pos = pos>180 ? 180 : (pos<0 ? 0 : pos);
    myservo.write(pos);
}

void setup()
{

    Serial.begin(38400);
    myservo.attach(9);
    cout << "init over!" << endl;
}

void loop()
{

    int val = getAnalog();                      // get value of A0
    
    posServo = map(val, 0, 1023, 0, 150);       // make val to 0-150

    if(posServo != posServoBuf)                 // if value change
    {
        cout << posServo << endl;
        posServoBuf = posServo;
        servoPos(posServo);                     // set servo position
        delay(10);                              // make sure servo stop
    }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/