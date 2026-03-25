#pragma once
#include "Car.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Weather.h"

class Circuit
{
    double length;
    Car *circuit[1000];
    double ranks[1000];
    int count = 0;
    Weather weather;
public:
    void SetLength(int length);
    void SetWeather(Weather W);
    void AddCar(Car * a);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();

};
