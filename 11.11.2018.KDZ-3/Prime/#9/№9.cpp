#include <iostream>
#include <cmath>

using namespace std;

double f (double a)
{
    return a*a*a;
}

bool sign(double b)
{
    return (b >= 0);
}

int main()
{
    double i = 0;
    double c = 1000;

    if (sign(i - c) != sign(i + c))
    {

    }
}
