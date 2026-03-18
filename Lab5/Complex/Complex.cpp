#include "complex.h"
#include <cmath>

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex operator +(const Complex& l, const Complex& r)
{
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}
Complex operator+(const Complex& l, double r)
{
    return Complex(l.real() + r, l.imag());
}
Complex operator+(double l, const Complex& r)
{
    return Complex(l + r.real(), r.imag());
}
Complex operator-(const Complex& l, const Complex& r)
{
    return Complex(l.real() - r.real(), l.imag() - r.imag());
}
Complex operator-(const Complex& l, double r)
{
    return Complex(l.real() - r, l.imag());
}
Complex operator-(double l, const Complex& r)
{
    return Complex(l - r.real(), -r.imag());
}
Complex operator*(const Complex& l, const Complex& r)
{
    return Complex(l.real() * r.real() - l.imag() * r.imag(), l.real() * r.imag() + l.imag() * r.real());
}
Complex operator*(const Complex& l, double r)
{
    return Complex(l.real() * r, l.imag() * r);
}
Complex operator*(double l, const Complex& r)
{
    return Complex(l * r.real(), l * r.imag());
}

Complex operator-(const Complex& obj)
{
    return Complex(-obj.real(), -obj.imag());
}

bool operator==(const Complex& l, const Complex& r)
{
    return abs(l.real()-r.real()) < 0.001 && abs(l.imag()-r.imag()) < 0.001;
}
bool operator!=(const Complex& l, const Complex& r)
{
    return !(l==r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    if(complex.real()==0 && complex.imag()==0)
        out << '0' ;
    else if(complex.real()!=0 && complex.imag() < 0)
        out << complex.real() << ' ' << '-' << ' ' << -complex.imag() << 'i' ;
    else if(complex.real()!=0 && complex.imag() > 0)
        out << complex.real() << ' ' << '+' << ' ' << complex.imag() << 'i' ;
    else if(complex.real() !=0 && complex.imag() == 0)
        out << complex.real() ;
    else if(complex.real() ==0 && complex.imag() != 0)
        out << complex.imag() << 'i' ;

    return out;
}

Complex& operator --(Complex & a)
{
    a = Complex(a.real() - 1, a.imag());
    return a;
}
Complex operator --(Complex & a,int)
{
    Complex old = a;
    --a;
    return old;
}
Complex& operator ++(Complex & a)
{
    a = Complex(a.real() + 1, a.imag());
    return a;
}
Complex operator ++(Complex & a,int)
{
    Complex old = a;
    ++a;
    return old;
}

