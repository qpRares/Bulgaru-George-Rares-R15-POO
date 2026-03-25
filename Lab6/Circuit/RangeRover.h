#pragma once
#include "Car.h"

class RangeRover : public Car
{
public:
    RangeRover()
    {
        capacity = 50;
        fuelconsumption = 4;
        averagerainspeed = 75;
        averagesunnyspeed = 100;
        averagesnowspeed = 60;
    }
    double GetCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather W) const override;
};

