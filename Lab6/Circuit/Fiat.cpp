#include "Fiat.h"

double Fiat::GetCapacity() const
{
    return this->capacity;
}

double Fiat::GetFuelConsumption() const
{
    return this->fuelconsumption;
}

double Fiat::GetAverageSpeed(Weather W) const
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

