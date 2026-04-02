#pragma once
#include <iostream>

template<typename T>
class Vector
{
    T* v;
    int size;
public:
    Vector()
    {
        v = nullptr;
        size = 0;
    }
    Vector(const Vector& a)
    {
        size = a.size;
        v = new T[size];
        for(int i=0; i<size; i++)
            v[i] = a.v[i];
    }
    void insert(int index, T element)
    {
        if(index == size && index == 0)
        {
            T* temp = new T[size + 1];
            temp[index] = element;
            delete[] v;
            v = temp;
            size++;
        }
        else
        {
            T* temp = new T[size +1];
            for(int i=0; i<index; i++)
                temp[i] = v[i];
            temp[index] = element;
            for(int i=index+1; i<size+1; i++)
                temp[i] = v[i - 1];

            delete[] v;
            v = temp;
            size++;
        }
    }
    void remove(int index)
    {
        if(index < 0 || index >= size)
            return;

        T* temp = new T[size - 1];

        for(int i = 0; i < index; i++)
            temp[i] = v[i];

        for(int i = index + 1; i < size; i++)
            temp[i - 1] = v[i];

        delete[] v;
        v = temp;
        size--;
    }
    void sort( int (*compare)(T, T) )
    {
        for(int i=0; i<size; i++)
            for(int j=i; j<size; j++)
                if(compare(v[i],v[j]))
                {
                    T aux;
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
    }
    void sort()
    {
        for(int i=0; i<size; i++)
            for(int j=i; j<size; j++)
                if(v[i] < v[j])
                {
                    T aux;
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
    }
    T& operator[](int index)
    {
        return v[index];
    }
    Vector& operator=(Vector& other)
    {
        if(this == &other)
            return *this;

        delete[] v;

        size = other.size;
        v = new T[size];

        for(int i = 0; i < size; i++)
            v[i] = other.v[i];

        return *this;
    }
    void print()
    {
        for(int i=0; i<size; i++)
            std::cout<<v[i]<<' ';
    }
    ~Vector()
    {
        delete[] v;
    }
};
