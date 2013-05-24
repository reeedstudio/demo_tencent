/*
  BeaconSensor.h
  2013 Copyright (c) Seeed Technology Inc.  All right reserved.

  Author:Frankie.Chu
  Date:Jan 11,2013
  
  Modify: Loovee
  Date:May 24,2013
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Wire.h>
#include <ADXL345.h>
#include <Streaming.h>

ADXL345 adxl;                   //variable adxl is an instance of the ADXL345 library

void adxlInit()
{
    adxl.powerOn();

    //set activity/ inactivity thresholds (0-255)
    adxl.setActivityThreshold(75);                  //62.5mg per increment
    adxl.setInactivityThreshold(75);                //62.5mg per increment
    adxl.setTimeInactivity(10);                     // how many seconds of no activity is inactive?
    
    //look of activity movement on this axes - 1 == on; 0 == off
    adxl.setActivityX(1);
    adxl.setActivityY(1);
    adxl.setActivityZ(1);

    //look of inactivity movement on this axes - 1 == on; 0 == off
    adxl.setInactivityX(1);
    adxl.setInactivityY(1);
    adxl.setInactivityZ(1);

    //look of tap movement on this axes - 1 == on; 0 == off
    adxl.setTapDetectionOnX(0);
    adxl.setTapDetectionOnY(0);
    adxl.setTapDetectionOnZ(1);

    //set values for what is a tap, and what is a double tap (0-255)
    adxl.setTapThreshold(50);                   //62.5mg per increment
    adxl.setTapDuration(15);                    //625us per increment
    adxl.setDoubleTapLatency(80);               //1.25ms per increment
    adxl.setDoubleTapWindow(200);               //1.25ms per increment

    //set values for what is considered freefall (0-255)
    adxl.setFreeFallThreshold(7);               //(5 - 9) recommended - 62.5mg per increment
    adxl.setFreeFallDuration(45);               //(20 - 70) recommended - 5ms per increment

    //setting all interrupts to take place on int pin 1
    //I had issues with int pin 2, was unable to reset it
    adxl.setInterruptMapping( ADXL345_INT_SINGLE_TAP_BIT,   ADXL345_INT1_PIN );
    adxl.setInterruptMapping( ADXL345_INT_DOUBLE_TAP_BIT,   ADXL345_INT1_PIN );
    adxl.setInterruptMapping( ADXL345_INT_FREE_FALL_BIT,    ADXL345_INT1_PIN );
    adxl.setInterruptMapping( ADXL345_INT_ACTIVITY_BIT,     ADXL345_INT1_PIN );
    adxl.setInterruptMapping( ADXL345_INT_INACTIVITY_BIT,   ADXL345_INT1_PIN );

    //register interrupt actions - 1 == on; 0 == off
    adxl.setInterrupt( ADXL345_INT_SINGLE_TAP_BIT, 1);
    adxl.setInterrupt( ADXL345_INT_DOUBLE_TAP_BIT, 1);
    adxl.setInterrupt( ADXL345_INT_FREE_FALL_BIT,  1);
    adxl.setInterrupt( ADXL345_INT_ACTIVITY_BIT,   1);
    adxl.setInterrupt( ADXL345_INT_INACTIVITY_BIT, 1);
}

void setup()
{
    Serial.begin(38400);
    adxlInit();
    
    cout << "init over" << endl;
}

void loop()
{

    double xyz[3];
    double ax,ay,az;
    adxl.getAcceleration(xyz);
    ax = xyz[0];
    ay = xyz[1];
    az = xyz[2];

    cout << "X = " << ax << "g" << endl;
    cout << "Y = " << ay << "g" << endl;
    cout << "Z = " << az << "g" << endl << endl;
    
    delay(100);

}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/