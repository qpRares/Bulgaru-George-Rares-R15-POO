#include "Sort.h"
#include <iostream>
using namespace std;
int main()
{

    Sort A(10,1,100);
    A.Print();
    cout<<'\n';

    int b[] = {5,4,3,2,1};
    A = Sort(b,5);
    A.Print();
    cout<<'\n';

    A = Sort();
    A.Print();
    cout<<'\n';

    A = Sort(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    A.Print();
    cout<<'\n';

    char c[] = "10,40,100,5,70";
    A = Sort(c);
    A.Print();
    cout<<'\n';
    cout<<'\n';

    A = Sort(10,1,100);
    A.Print();
    cout<<'\n';
    A.BubbleSort(1);
    A.Print();
    cout<<'\n';
    cout<<'\n';

    A = Sort(10,1,100);
    A.Print();
    cout<<'\n';
    A.BubbleSort(0);
    A.Print();
    cout<<'\n';
    cout<<'\n';

    A = Sort(10,1,100);
    A.Print();
    cout<<'\n';
    A.InsertSort(1);
    A.Print();
    cout<<'\n';
    cout<<'\n';

    A = Sort(10,1,100);
    A.Print();
    cout<<'\n';
    A.InsertSort(0);
    A.Print();
    cout<<'\n';
    cout<<'\n';

    A = Sort(10,1,100);
    A.Print();
    cout<<'\n';
    A.QuickSort(1);
    A.Print();
    cout<<'\n';
    cout<<'\n';

    A = Sort(10,1,100);
    A.Print();
    cout<<'\n';
    A.QuickSort(0);
    A.Print();
    cout<<'\n';
    cout<<'\n';
    return 0;
}
