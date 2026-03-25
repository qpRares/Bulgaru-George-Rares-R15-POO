#pragma once
#include "Weather.h"
class Car
{
public:
    double capacity;
    double fuelconsumption;
    double averagerainspeed;
    double averagesunnyspeed;
    double averagesnowspeed;
    virtual double GetCapacity() const = 0;
    virtual double GetFuelConsumption() const = 0;
    virtual double GetAverageSpeed(Weather W) const = 0;

};
