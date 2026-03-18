#include "Number.h"
#include <iostream>
Number::Number(const char* value,int base)
{
    this->base = base;
    this->nr = 0;
    int i=0;
    while(value[i]!='\0')
    {
        if(value[i] >= 'A' && value[i] <= 'F')
            this->nr = this->nr * base + (10 + value[i] - 'A');
        else
            this->nr = this->nr * base + (value[i] - '0');
        i++;
    }
}

Number::~Number()
{
    this->nr = 0;
    this->base = 0;
}

Number::Number(const Number & a)
{
    this->nr = a.nr;
    this->base = a.base;
}

Number::Number(Number&& a)
{
    this->nr = a.nr;
    this->base = a.base;

    a.nr = 0;
    a.base = 0;
}

Number::Number(int a)
{
    this->nr = a;
    if(this->base == 0)
        this->base = 10;
}

Number operator +(const Number & a, const Number & b)
{
    int resultnr = a.nr + b.nr;
    int resultbase;
    if(a.base > b.base)
        resultbase = a.base;
    else
        resultbase = b.base;
    Number C("0",10);
    C.nr = resultnr;
    C.base = resultbase;
    return C;

}

Number operator -(const Number & a, const Number & b)
{
    int resultnr = a.nr - b.nr;
    int resultbase;
    if(a.base > b.base)
        resultbase = a.base;
    else
        resultbase = b.base;
    Number C("0",10);
    C.nr = resultnr;
    C.base = resultbase;
    return C;

}

char Number::operator[](int index)
{
    if (nr == 0)
    {
        if (index == 0) return '0';
        return '0';
    }

    int digits = this->GetDigitsCount();
    int p = 1;

    for (int i = 1; i < digits; i++)
        p *= base;

    for (int i = 0; i < index; i++)
        p /= base;

    int digit = (nr / p) % base;

    if (digit < 10)
        return '0' + digit;
    else
        return 'A' + (digit - 10);
}
bool Number::operator >(const Number & a)
{
    return this->nr > a.nr;
}

bool Number::operator <(const Number & a)
{
    return this->nr < a.nr;
}

bool Number::operator >=(const Number & a)
{
    return this->nr >= a.nr;
}

bool Number::operator <=(const Number & a)
{
    return this->nr <= a.nr;
}

bool Number::operator ==(const Number & a)
{
    return this->nr == a.nr;
}

Number& Number::operator +=(const Number & a)
{
    *this = *this + a;
    return *this;
}

Number& Number::operator =(const Number & a)
{
    this->nr = a.nr;
    this->base = a.base;
    return *this;
}

Number& Number::operator =(Number&& a)
{
    if (this != &a)
    {
        this->nr = a.nr;
        this->base = a.base;

        a.nr = 0;
        a.base = 0;
    }
    return *this;
}

Number& Number::operator =(int a)
{
    this->nr = a;
    if(this->base == 0) base = 10;
    return *this;
}

Number& Number::operator =(const char* value)
{
    int b = base;
    if (b == 0) b = 10;

    int x = 0;

    for (int i = 0; value[i] != '\0'; i++)
    {
        int digit;

        if (value[i] >= '0' && value[i] <= '9')
            digit = value[i] - '0';
        else if (value[i] >= 'A' && value[i] <= 'F')
            digit = 10 + (value[i] - 'A');
        else if (value[i] >= 'a' && value[i] <= 'f')
            digit = 10 + (value[i] - 'a');
        else
            continue;

        x = x * b + digit;
    }

    nr = x;
    return *this;
}
Number& Number::operator --()
{
    int digits = this->GetDigitsCount();
    digits --;
    int p = 1;
    while(digits)
        {
            p = p * base;
            digits --;
        }
    this->nr = nr % p;
    return *this;
}

Number Number::operator --(int)
{
    Number old(*this);
    this->nr = this->nr / this->base;
    return old;
}
void Number::SwitchBase(int newBase)
{
    this->base = newBase;
}

void Number::Print()
{
    if (nr == 0)
    {
        std::cout << 0;
        return;
    }

    int temp = nr;
    char buffer[32];
    int index = 0;

    while (temp > 0)
    {
        int digit = temp % base;

        if (digit < 10)
            buffer[index++] = '0' + digit;
        else
            buffer[index++] = 'A' + (digit - 10);

        temp /= base;
    }

    for (int i = index - 1; i >= 0; i--)
        std::cout << buffer[i];
    std::cout<<'\n';
}

int Number::GetDigitsCount()
{
    if(this->nr == 0)
        return 1;
    int temp = this->nr;
    int digits = 0;
    while(temp > 0)
    {
        digits ++;
        temp = temp / base;
    }
    return digits;
}

int Number::GetBase()
{
    return this->base;
}
