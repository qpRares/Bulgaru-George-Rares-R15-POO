#include "Math.h"
#include <iostream>
using namespace std;
int main()
{
    Math A;
    cout<<A.Add(1,2)<<'\n';
    cout<<A.Add(1,2,3)<<'\n';
    cout<<A.Add(1.1,2.2)<<'\n';
    cout<<A.Add(1.1,2.2,3.3)<<'\n';
    cout<<A.Mul(1,2)<<'\n';
    cout<<A.Mul(1,2,3)<<'\n';
    cout<<A.Mul(1.1,2.2)<<'\n';
    cout<<A.Mul(1.1,2.2,3.3)<<'\n';
    cout<<A.Add(5,1,2,3,4,5)<<'\n';

    char *s = A.Add("asd","dsa");
    cout<<s<<'\n';
    delete[] s;

    s = A.Add("asd",nullptr);
    if(s)
        cout<<s<<'\n';
    else
        cout<<"nullptr"<<'\n';
    delete[] s;

    s = A.Add(nullptr,"dsa");
    if(s)
        cout<<s<<'\n';
    else
        cout<<"nullptr"<<'\n';
    delete[] s;

    return 0;
}
