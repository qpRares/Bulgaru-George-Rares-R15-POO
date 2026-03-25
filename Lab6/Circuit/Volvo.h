#pragma once
#include "Car.h"

class Volvo : public Car
{
public:
    Volvo()
    {
        capacity = 30;
        fuelconsumption = 3;
        averagerainspeed = 65;
        averagesunnyspeed = 95;
        averagesnowspeed = 50;
    }
    double GetCapacity() const override;
    double GetFuelConsumption() const override;
    double GetAverageSpeed(Weather W) const override;
};
