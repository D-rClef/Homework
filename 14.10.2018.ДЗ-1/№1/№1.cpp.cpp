/*Напишите программу проверяющую является ли число составным. В
программе гарантируется, что число - натуральное.*/

#include <iostream>


using namespace std;

int main()
{
    int n;
    int k = 0;
    int i;
    cin>>n;

    if (n == 1)
    {
        cout<<"Unit";
    }
    else
    {
        for (int i = 2; i < n; i++ )
            if ((n % i)==0)
            {
                k = 1;
                break;
            };
        if (k==1)
        {
            cout<<"Composite";
        }
        else
            {cout<<"Prime";};
    };

    return 0;
}

