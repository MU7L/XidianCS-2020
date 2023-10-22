#include <iostream>
#include <string>

using namespace std;

class Complex
{
public:
    double real, imag;
    Complex(double initReal = 0.0, double initImag = 0.0);
    Complex operator+(Complex &c);
    Complex operator-(Complex &c);
    Complex operator*(Complex &c);
    Complex operator/(Complex &c);
    string toString();
};

Complex::Complex(double initReal, double initImag) : real(initReal), imag(initImag) {}

Complex Complex::operator+(Complex &c)
{
    Complex tmp;
    tmp.real = this->real + c.real;
    tmp.imag = this->imag + c.imag;
    return tmp;
}

Complex Complex::operator-(Complex &c)
{
    Complex tmp;
    tmp.real = this->real - c.real;
    tmp.imag = this->imag - c.imag;
    return tmp;
}

Complex Complex::operator*(Complex &c)
{
    Complex tmp;
    tmp.real = this->real * c.real - this->imag * c.imag;
    tmp.imag = this->real * c.imag + this->imag * c.real;
    return tmp;
}

Complex Complex::operator/(Complex &c)
{
    if (c.real == 0 && c.imag == 0)
    {
        Complex err(0.0, 0.0);
        return err;
    }
    double m2 = c.real * c.real + c.imag * c.imag;
    Complex tmp(c.real / m2, -c.imag / m2);
    tmp = *this * tmp;
    return tmp;
}

string Complex::toString()
{
    string str = "";
    if (imag > 0.0)
    {
        str = to_string(real) + "+" + to_string(imag) + "i";
    }
    else
    {
        str = to_string(real) + to_string(imag) + "i";
    }
    return str;
}

int main()
{
    Complex a(2.0, 4.0);
    Complex b(1.0, 2.0);
    cout << "a = " << a.toString() << endl;
    cout << "b = " << b.toString() << endl;
    cout << "a + b = " << (a + b).toString() << endl;
    cout << "a - b = " << (a - b).toString() << endl;
    cout << "a * b = " << (a * b).toString() << endl;
    cout << "a / b = " << (a / b).toString() << endl;
    return 0;
}