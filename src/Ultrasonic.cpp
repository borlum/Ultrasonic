/*
Ultrasonic.cpp - Arduino Library for Ultrasonic Sensor
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

#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int dataPin, int triggerPin, int power, bool reverseSignal)
{
    _dataPin = dataPin;
    _triggerPin = triggerPin;
    _power = power;
    _reverseSignal = reverseSignal;
    
    pinMode(_power, OUTPUT);
    digitalWrite(_power, HIGH);
}
void Ultrasonic::turnOn()
{
    digitalWrite(_power, HIGH);
    delay(200);
}
void Ultrasonic::turnOff()
{
    digitalWrite(_power, LOW);
}
int Ultrasonic::getDistance()
{
    //Set triggerPin to OUTPUT mode
    pinMode(_triggerPin, OUTPUT);
    
    //Send low-high-low pulses
    if (_reverseSignal == true){
        digitalWrite(_triggerPin, LOW);
        delayMicroseconds(2);
        digitalWrite(_triggerPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(_triggerPin, LOW);
        delayMicroseconds(2);
    } else {
        digitalWrite(_triggerPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(_triggerPin, LOW);
        delayMicroseconds(200);
        digitalWrite(_triggerPin, HIGH);
        delayMicroseconds(200);
    }
    
    //Listening for echo pulse
    pinMode(_dataPin, INPUT);
    bool val;
    
    //Wait, until a high value is read
    if (_reverseSignal == true){
        do {
            val = digitalRead(_dataPin);
        } while (val == LOW);
    } else {
        do {
            val = digitalRead(_dataPin);
        } while (val == HIGH);
    }
    
    int timeCount = 0;
    //Count, until low value is read again
    if (_reverseSignal == true){
        do {
            val = digitalRead(_dataPin);
            timeCount ++;
            delayMicroseconds(50);
        } while (val == HIGH);
    } else {
        do {
            val = digitalRead(_dataPin);
            timeCount ++;
            delayMicroseconds(50);
        } while (val == LOW);
    }
    
    //Return values (if value less than 300 cm, it is acceptable)
    if (timeCount >= 0 && timeCount < 300){
        return timeCount;
    }
    //Otherwise, we return -1
    else {
        return -1;
    }
}
int Ultrasonic::getMean(int readings, int delayTime)
{
    int sum = 0;
    
    for (int i=0; i<readings; i++){
        sum += getDistance();
        delay(delayTime);
    }
    
    return sum/readings;
}
bool Ultrasonic::phfmSmaller(int dist, int readings)
{
    return false;
}
bool Ultrasonic::phfmBigger(int dist, int readings)
{
    return false;
}