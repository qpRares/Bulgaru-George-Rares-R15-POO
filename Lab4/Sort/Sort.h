#pragma once

class Sort
{
    // add data members
    int *a;
    int count;
    void QuickSortHelper(int left, int right, bool ascendent);
    int Partition(int left, int right, bool ascendent);
public:
    // add constuctors
    Sort(int count, int min, int max);
    Sort();
    Sort(int a[],int count);
    Sort(int count,...);
    Sort(const char a[]);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

