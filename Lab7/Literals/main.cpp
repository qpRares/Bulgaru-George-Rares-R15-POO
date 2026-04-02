#include <iostream>
using namespace std;

float operator "" _Kelvin(unsigned long long value)
{
    return value - 273.15;
}
float operator "" _Fahrenheit(unsigned long long value)
{
    return (value - 32.0) * 5.0 / 9.0;
}


int main() {

    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout<<a<<' '<<b;
    return 0;
}
