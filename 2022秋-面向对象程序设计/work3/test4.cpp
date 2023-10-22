#include <iostream>

using namespace std;

class Date
{
private:
    int year, moon, day, hour, minute, second;

public:
    Date(int y, int mo, int d, int h, int mi, int s);
    friend class Time;
};

Date::Date(int y, int mo, int d, int h, int mi, int s) : year(y), moon(mo), day(d), hour(h), minute(mi), second(s) {}

class Time
{
public:
    static void display(const Date &d);
};

void Time::display(const Date &d)
{
    cout << "year:\t" << d.year << "\n"
         << "moon:\t" << d.moon << "\n"
         << "hour:\t" << d.hour << "\n"
         << "minute:\t" << d.minute << "\n"
         << "second:\t" << d.second << endl;
}

int main()
{
    Date d(2022, 11, 9, 20, 19, 0);
    Time::display(d);
    return 0;
}