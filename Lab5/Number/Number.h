#pragma once
class Number
{
   // add data members
   int nr = 0;
   int base = 0;
public:
   Number(const char * value, int base); // where base is between 2 and 16
   ~Number();

   // add operators and copy/move constructor
   Number(const Number & a);
   Number(int a);
   friend Number operator +(const Number & a, const Number & b);

   friend Number operator -(const Number & a, const Number & b);
   char operator[](int index);
   bool operator >(const Number & a);
   bool operator <(const Number & a);
   bool operator >=(const Number & a);
   bool operator <=(const Number & a);
   bool operator ==(const Number & a);
   Number& operator +=(const Number & a);
   Number& operator =(const Number & a);
   Number& operator =(int value);
   Number& operator =(const char* value);
   Number& operator --();
   Number operator --(int);
   void SwitchBase(int newBase);
   void Print();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base
};
