#pragma once
#include "Car.h"

class BMW : public Car
{
public:
    BMW()
    {
        capacity = 40;
        fuelconsumption = 5;
        averagerainspeed = 70;
        averagesunnyspeed = 120;
        averagesnowspeed = 60;
    }
    double GetCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather W) const override;
};

