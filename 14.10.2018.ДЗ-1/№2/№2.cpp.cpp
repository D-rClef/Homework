/*�������� ��������� ��������� �������� �� ������ �������. ����� ������
�� ������ X � N ����� ����� ����� ����� Y, ��� ������� �� ������� X*Y �� N
��������� �������. � ��������� �������������, ��� ��� ����� - �����������*/

#include <iostream>

using namespace std;

int main()
{
    int X, Y, N, i;
    int k = 1;
    cin>>X;
    cin>>N;

    for (int i = 2; i<=X; i++)
    {
        if ((X % i == 0) & (N % i == 0))
        {
            k = 0;
            break;
        };
    };
    if (k==0)
        {cout<<"None";}
    else
    {
        for (int i = 1; 1==1; i++)
        {
            if (((X*i) % N)==1)
            {
                Y = i;
                break;
            };
        };
        cout<<Y;
    };
    return 0;
}
