#include "Volvo.h"

double Volvo::GetCapacity() const
{
    return this->capacity;
}

double Volvo::GetFuelConsumption() const
{
    return this->fuelconsumption;
}

double Volvo::GetAverageSpeed(Weather W) const
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
