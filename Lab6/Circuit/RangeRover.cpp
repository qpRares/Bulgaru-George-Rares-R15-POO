#include "RangeRover.h"

double RangeRover::GetCapacity() const
{
    return this->capacity;
}

double RangeRover::GetFuelConsumption() const
{
    return this->fuelconsumption;
}

double RangeRover::GetAverageSpeed(Weather W) const
{
    if(W == Weather::Rain)
        return this->averagerainspeed;
    else if(W == Weather::Snow)
        return this->averagesnowspeed;
    else if(W == Weather::Sunny)
        return this->averagesunnyspeed;
    else
        return 0;
}

