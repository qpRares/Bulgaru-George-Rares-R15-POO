#include "BMW.h"

double BMW::GetCapacity() const
{
    return this->capacity;
}

double BMW::GetFuelConsumption() const
{
    return this->fuelconsumption;
}

double BMW::GetAverageSpeed(Weather W) const
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
