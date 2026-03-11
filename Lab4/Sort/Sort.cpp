#include "Sort.h"
#include <random>
#include <cstdarg>
#include <iostream>

Sort::Sort(int count, int min, int max)
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    this->a = new int[count];
    this->count = count;

    for(int i=0; i<count; i++)
        a[i] = dist(gen);
}

Sort::Sort() : a(nullptr), count(0)
{

}

Sort::Sort(int a[],int count)
{
    this->a = new int[count];
    this->count = count;
    for(int i=0; i<count; i++)
        this->a[i] = a[i];
}

Sort::Sort(int count,...)
{
    va_list args;
    va_start(args,count);

    this->a = new int[count];
    this->count = count;
    for(int i=0; i<count; i++)
        a[i] = va_arg(args,int);
    va_end(args);
}

Sort::Sort(const char a[])
{
    this->count = 0;
    int i=0,j=0;
    while(a[i]!='\0') i++;

    int *temp = new int[i];
    i = 0;
    while(a[i]!='\0')
    {
        if(a[i]==',')
        {
            int nr=0;
            while(j<i)
            {
                nr = nr * 10 + a[j] - '0';
                j++;
            }

            j++;
            temp[this->count++] = nr;
        }
        i++;
    }
    int nr=0;
    while(j<i)
    {
        nr = nr * 10 + a[j] - '0';
        j++;
    }

    j++;
    temp[this->count++] = nr;
    this->a = new int[this->count];
    for(int i=0; i<this->count; i++)
        this->a[i] = temp[i];
    delete[] temp;
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < this->count; i++)
    {
        int key = this->a[i];
        int j = i - 1;

        if (ascendent)
        {
            while (j >= 0 && this->a[j] > key)
            {
                this->a[j + 1] = this->a[j];
                j--;
            }
        }
        else
        {
            while (j >= 0 && this->a[j] < key)
            {
                this->a[j + 1] = this->a[j];
                j--;
            }
        }

        this->a[j + 1] = key;
    }
}

int Sort::Partition(int left, int right, bool ascendent)
{
    int pivot = this->a[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (ascendent)
        {
            if (this->a[j] <= pivot)
            {
                i++;
                std::swap(this->a[i], this->a[j]);
            }
        }
        else
        {
            if (this->a[j] >= pivot)
            {
                i++;
                std::swap(this->a[i], this->a[j]);
            }
        }
    }

    std::swap(this->a[i + 1], this->a[right]);
    return i + 1;
}

void Sort::QuickSortHelper(int left, int right, bool ascendent)
{
    if (left < right)
    {
        int pivotIndex = Partition(left, right, ascendent);

        QuickSortHelper(left, pivotIndex - 1, ascendent);
        QuickSortHelper(pivotIndex + 1, right, ascendent);
    }
}

void Sort::QuickSort(bool ascendent)
{
    QuickSortHelper(0, this->count - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
    for(int i=0; i<count; i++)
        for(int j=i; j<count; j++)
            if(a[i] < a[j] && !ascendent)
            {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
            else if(a[i] > a[j] && ascendent)
            {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
}

void Sort::Print()
{
    for(int i=0; i<this->count; i++)
        std::cout<<this->a[i]<<' ';
}

int Sort::GetElementsCount()
{
    return this->count;
}

int Sort::GetElementFromIndex(int index)
{
    return this->a[index];
}
