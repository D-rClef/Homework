/* Напишите переборную программу программу, вычисляющую значение функции Эйлера для числа n. 
Программа должна работать не более чем за O(n* log n) шагов. */

#include <iostream>
using namespace std;

int GCD(int x, int y)
{
    while (y)
    {
        x %= y;
        swap(x,y);
    };
    return x;
}

int main()
{
    int n;
    cin >> n;
    int eul = 1;
    for(int i = 2; i < n; i++)
    {
        if (GCD(i, n) == 1) {eul++;};
    };

    cout << eul;
}
