/* Напишите функции min, max, avg, med, процедуру swap принимающие в себя
три вещественных аргумента и программу с примером из использования. min -
находит минимальное из трех значений, max - максимальное, avg - среднее
арифметическое, med - медианное, swap - переставляет значения по кругу */

#include <iostream>

using namespace std;

float min (float a, float b, float c)
{
    if (a > b) {a = b;};
    if (a > c) {a = c;};
    return a;
}

float max (float a, float b, float c)
{
    if (a < b) {a = b;};
    if (a < c) {a = c;};
    return a;
}

float avg (float a, float b, float c)
{
    a = (a+b+c)/3;
    return a;
}

float med (float a, float b, float c)
{
    if ((a > min(a,b,c)) & (a < max(a,b,c)))
      {return a;}
    else
    {
        if ((b > min(a,b,c)) & (b < max(a,b,c)))
          {return b;}
        else {return c;};
    };
}

void swap (float* a, float* b, float* c)
{
    float k = *b;
    float n = *c;
    *b = *a;
    *a = n;
    *c = k;
    return;
}

int main()
{
    float x, y, z;
    cin>>x;
    cin>>y;
    cin>>z;
    cout<<min(x, y , z)<<'\n';
    cout<<max(x, y, z)<<'\n';
    cout<<avg(x, y, z)<<'\n';
    cout<<med(x, y, z)<<'\n';
    swap(&x, &y, &z);
    cout<<x<<' '<<y<<' '<<z;
    return 0;
}
