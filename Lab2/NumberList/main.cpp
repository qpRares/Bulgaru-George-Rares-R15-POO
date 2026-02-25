#include "NumberList.h"
using namespace std;
int main()
{
    NumberList N;
    N.Init();
    N.Add(3);
    N.Print();
    N.Add(8);
    N.Add(2);
    N.Add(1);
    N.Add(7);
    N.Add(6);
    N.Add(5);
    N.Add(4);
    N.Print();
    N.Sort();
    N.Print();
    N.Add(10);
    N.Add(9);
    N.Print();
    N.Sort();
    N.Print();
    N.Init();
    N.Add(2);
    N.Print();
    N.Add(1);
    N.Print();
    N.Sort();
    N.Print();
    return 0;
}
