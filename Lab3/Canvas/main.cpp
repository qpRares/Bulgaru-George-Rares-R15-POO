#include "Canvas.h"
#include <iostream>
using namespace std;
int main()
{
    Canvas A(100,100);
    A.DrawCircle(25,25,9,'#');
    A.FillCircle(25,25,9,'*');
    A.DrawRect(45,45,60,60,'#');
    A.FillRect(45,45,60,60,'*');
    A.SetPoint(2,2,'#');
    A.DrawLine(5,40,15,45,'#');
    A.Print();
    return 0;
}
