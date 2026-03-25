#pragma once
#include "Car.h"

class Seat : public Car
{
public:
    Seat()
    {
        capacity = 1;
        fuelconsumption = 4;
        averagerainspeed = 70;
        averagesunnyspeed = 100;
        averagesnowspeed = 65;
    }
    double GetCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather W) const override;
};

