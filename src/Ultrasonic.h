/*
Ultrasonic.h - Arduino Library for Ultrasonic Sensor
Created by MJC; Mikkel, Joakim & Casper
April 2013
*/

/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * MJC wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy us a beer in return.
 * /MJC; Mikkel, Joakim & Casper
 * ----------------------------------------------------------------------------
 */

#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

class Ultrasonic
{
    public:
        Ultrasonic(int dataPin, int triggerPin, int power, bool reverseSignal);
        void turnOn();
        void turnOff();
        int getDistance();
        int getMean(int readings, int delayTime);
        bool phfmSmaller(int dist, int readings);
        bool phfmBigger(int dist, int readings);
    private:
        int _dataPin, _triggerPin, _power;
        bool _reverseSignal;
};

#endif