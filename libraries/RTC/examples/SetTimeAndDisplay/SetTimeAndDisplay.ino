/*
  SetTimeAndDisplay.ino
  2013 Copyright (c) Seeed Technology Inc.  All right reserved.

  Author:FrankieChu
  Jan 19,2013

  Modify: Loovee
  May 24, 2013

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
#include <DS1307.h>
#include <Streaming.h>

int year    = 2013;
int month   = 5;
int day     = 24;
int week    = FRI;
int hour    = 16;
int minute  = 35;
int second  = 30; 

DS1307 clock;                                   // define a object of DS1307 class

void setup()
{
    Serial.begin(38400);
    clock.begin();
    clock.fillByYMD(year, month, day);          // Jan 19,2013
    clock.fillByHMS(hour, minute, second);      // 15:28 30"
    clock.fillDayOfWeek(week);                  // Saturday
    clock.setTime();                            // write time to the RTC chip
    
    cout << "init over" << endl;
}

void loop()
{
    printTime();
}

void printTime()
{

    clock.getTime();

    cout << clock.hour << ":" << clock.minute << ":" << clock.second << "    ";
    cout << clock.month << "/" << clock.dayOfMonth << "/" << clock.year+2000 << " " << clock.dayOfMonth << "*";
    
    switch (clock.dayOfWeek)// Friendly printout the weekday
    {
        case MON:
        cout << "MON";
        break;
        
        case TUE:
        cout << "TUE";
        break;
        
        case WED:
        cout << "WED";
        break;
        
        case THU:
        cout << "THU";
        break;
        
        case FRI:
        cout << "FRI";
        break;
        
        case SAT:
        cout << "SAT";
        break;
        
        case SUN:
        cout << "SUN";
        break;
        
        default:
        cout << "unavailable command" << endl;
    }
    
    cout << endl;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/