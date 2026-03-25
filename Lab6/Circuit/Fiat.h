#pragma once
#include "Car.h"

class Fiat : public Car
{
public:
    Fiat()
    {
        capacity = 25;
        fuelconsumption = 2;
        averagerainspeed = 50;
        averagesunnyspeed = 80;
        averagesnowspeed = 40;
    }
    double GetCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather W) const override;
};
