/* Напишите программу находящую минимальную сумму пары элементов массива
отстоящих друг от друга не менее чем на 4 элемента(первый и пятый элемент
могут подходить, а первый и третий - нет). Эффективность в данной программе
не приоритетна.*/

#include <iostream>

using namespace std;

int main()
{
    int N, i, j;
    cin>>N;
    int Oh[N];
    int s = 0;

    for(int i = 0; i < N; i++)
    {
        cin>>Oh[i];
        if (Oh[i] >= 0)
         {s += Oh[i];}
        else {s += -1*Oh[i];};
    };

    if (N<5)
        {cout<<"Invalid condition";}
    else
    {
        for(int i = 0; i < N; i++)
    {
        for(int j = i+4; j < N; j++)
        {
            if ((Oh[i]+Oh[j]) <= s)
            {
                s = Oh[i] + Oh[j];
            };
        };
    };
    cout<<s;
    };

    return 0;
}
