/* Напишите процедуру, дописывающую к каждому элементу динамически
выделенного массива справа его квадрат.({1,2,3,4}->{1,1,2,4,3,9,4,16}). По
окончании работы процедуры количество выделенной памяти должно
увеличиться. */

#include <iostream>
using namespace std;

int sqr (int o)
{
    return o*o;
}

void zachem (int* &a, int b)
{
    int* not_plagiat = new int [b];
    for (int i = 0; i < b; i++)
    {
        *(not_plagiat + i) = sqr(*(a + i));
    };

    int c = 2*b;
    int* again = new int[c];
    for (int i = 0; i < c; i++)
    {
        if ((i % 2) == 0)
        {
            *(again + i) = *(a + (i/2));
        }
        else
        {
            *(again + i) = *(not_plagiat + ((i-1)/2));
        };
    };

    delete[]not_plagiat;

    a = again;
}

int main()
{
    int n;
    cin >> n;
    int* gospodi = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> *(gospodi + i);
    };

    zachem(gospodi, n);
    n += n;

    for (int i = 0; i < n; i++)
    {
        cout << *(gospodi + i) << " ";
    };
}
