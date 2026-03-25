#include "Circuit.h"
#include <iostream>
void Circuit::SetLength(int length)
{
    this->length = length;
}
void Circuit::SetWeather(Weather W)
{
    this->weather = W;
}
void Circuit::AddCar(Car * a)
{
    this->circuit[this->count++] = a;
}
void Circuit::Race()
{
    for(int i=0; i<count; i++)
    {

        double maxdistance = this->circuit[i]->GetCapacity() * 100.00 / this->circuit[i]->GetFuelConsumption();
        if(maxdistance < length)
            this->ranks[i] = -1;
        else
            this->ranks[i] = this->length/this->circuit[i]->GetAverageSpeed(this->weather);
    }
}
void Circuit::ShowFinalRanks()
{
    for(int i = 0; i < count - 1; i++)
        for(int j = i + 1; j < count; j++)
        {
            if(ranks[i] != -1 && ranks[j] != -1 && ranks[i] > ranks[j])
            {
                double aux = ranks[i];
                ranks[i] = ranks[j];
                ranks[j] = aux;
                Car *aux1 = circuit[i];
                circuit[i] = circuit[j];
                circuit[j] = aux1;
            }
        }

    for(int i = 0; i < count; i++)
        if(ranks[i] != -1)
            std::cout << ranks[i] << " ";
    std::cout << '\n';
}
void Circuit::ShowWhoDidNotFinish()
{
    for(int i=0; i<count; i++)
        if(this->ranks[i] == -1)
            std::cout<<i<<' ';
}
