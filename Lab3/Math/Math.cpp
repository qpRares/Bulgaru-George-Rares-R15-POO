#include "Math.h"
#include <cstdarg>

int Math::Add(int a, int b)
{
    return static_cast<int>(a + b);
}

int Math::Add(int a, int b, int c)
{
    return static_cast<int>(a + b + c);
}

int Math::Add(double a, double b)
{
    return static_cast<int>(a + b);
}

int Math::Add(double a, double b, double c)
{
    return static_cast<int>(a + b + c);
}

int Math::Mul(int a, int b)
{
    return static_cast<int>(a * b);
}

int Math::Mul(int a, int b, int c)
{
    return static_cast<int>(a * b * c);
}

int Math::Mul(double a, double b)
{
    return static_cast<int>(a * b);
}

int Math::Mul(double a, double b, double c)
{
    return static_cast<int>(a * b * c);
}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args,count);

    int s = 0;

    for(int i=0;i<count;i++)
        {
            int val = va_arg(args, int);
            s += val;
        }
    va_end(args);
    return static_cast<int>(s);
}

char* Math::Add(const char *a, const char *b)
{
    if(a == nullptr) return nullptr;
    if(b == nullptr) return nullptr;

    int i=0,j=0;
    int size_a = 0;
    int size_b = 0;
    while(a[size_a] != '\0') size_a ++;
    while(b[size_b] != '\0') size_b ++;
    char *sum = new char[size_a + size_b + 1];
    while(a[i] != '\0')
    {
        sum[i] = a[i];
        i++;
    }
    while(b[j] != '\0')
    {
        sum[i] = b[j];
        i++;
        j++;
    }
    sum[i] = '\0';
    return static_cast<char *>(sum);
}

