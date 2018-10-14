/* Напишите функцию sort упорядывающую массив целых чисел и программу с
примером её использования. В коде запрещается использовать обращения к
массиву по индексу( Arr[i] ), т.е. нужно использовать указательную арифметику.
Эффективность в данной программе не приоритетна. Количество аргументов
функции не должно превышать 2. */

#include <iostream>

using namespace std;

void sort(int N, int* p)
{
     int* M;
     M = p;
     for (int i = 0; i < N; i++)
     {
         if (*(p+i) < *M)
         {
             M = (p+i);
         };
     };
     swap(*p, *M);
     N = N - 1;
     p = p + 1;
     if (N != 0)
     {
        sort(N, p);
     };
     
     return;
}


int main()
{
    int n;
    cin>>n;
    int* q = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin>>*(q+i);
    };
    sort(n, q);
    for (int i = 0; i < n; i++)
    {
        cout<<*(q+i)<<' ';
    };
     
    delete[]q;
     
    return 0;
}
