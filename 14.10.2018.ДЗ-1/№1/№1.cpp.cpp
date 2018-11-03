/*Напишите программу проверяющую является ли число составным. В
программе гарантируется, что число - натуральное.*/

#include <iostream>
#include <cmath>


using namespace std;

int main()
{
    double G, m, d_c, R, L, d, T, T1, p = 3.141592653589793238462643383279502884;
    cin >> m >> d_c >> R >> L >> d >> T >> T1;
    m /= 1000;
    d /= 2000;
    d_c /= 2000;
    R /= 1000;
    T /= 1000;
    T1 /= 1000;
    L /= 1000;

    d_c = pow(d_c, 2);
    R = pow(R, 2);
    R *= 2;
    d = pow(d, 4);
    T = pow(T, 2);
    T1 = pow(T1, 2);

    G = ((8*p*L*m*(d_c+R))/(d*(T1-T)));
    cout << G;

    return 0;
}

