#include <iostream>
#include <string>

using namespace std;

const double pi = 3.1415;


class Shape
{
public:
    string name;
    virtual double area() = 0;
};

class Circle : public Shape
{
private:
    double r;

public:
    Circle(double m_r);
    double area();
};

Circle::Circle(double m_r) : r(m_r)
{
    name = "Circle";
}

double Circle::area()
{
    return pi * r * r;
}


class Square : public Shape
{
private:
    double a;

public:
    Square(double m_a);
    double area();
};

Square::Square(double m_a) : a(m_a)
{
    name = "Square";
}

double Square::area()
{
    return a * a;
}


class Rectangle : public Shape
{
private:
    double l;
    double w;

public:
    Rectangle(double m_l, double m_w);
    double area();
};

Rectangle::Rectangle(double m_l, double m_w) : l(m_l), w(m_w)
{
    name = "Rectangle";
}

double Rectangle::area()
{
    return l * w;
}


class Trapezoid : public Shape
{
private:
    double l1;
    double l2;
    double h;

public:
    Trapezoid(double m_l1, double m_l2, double m_h);
    double area();
};

Trapezoid::Trapezoid(double m_l1, double m_l2, double m_h) : l1(m_l1), l2(m_l2), h(m_h)
{
    name = "Trapezoid";
}

double Trapezoid::area()
{
    return (l1 + l2) * h / 2.0;
}


class Triangle : public Shape
{
private:
    double a;
    double h;

public:
    Triangle(double m_a, double m_h);
    double area();
};

Triangle::Triangle(double m_a, double m_h) : a(m_a), h(m_h)
{
    name = "Triangle";
}

double Triangle::area()
{
    return 0.5 * a * h;
}


int main()
{
    Shape *ss[5];
    ss[0] = new Circle(1.0);
    ss[1] = new Square(1.0);
    ss[2] = new Rectangle(1.0, 2.0);
    ss[3] = new Trapezoid(1.0, 2.0, 3.0);
    ss[4] = new Triangle(1.0, 2.0);

    for (Shape *s : ss)
    {
        cout << s->name << "'s area:\t" << s->area() << endl;
    }
    return 0;
}