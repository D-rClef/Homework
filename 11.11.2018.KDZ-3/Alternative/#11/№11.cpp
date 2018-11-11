#include <iostream>
#include <cstdio>

using namespace std;

int Length(char* a)
{
    int b = 0;
    while(*a++)
    {
        b++;
    };
    return b;
}

struct String
{
   char* symb = new char [256];
   int n = Length(symb);

    void input ()
    {
        gets(symb);
        n = Length(symb);
    }

    void output()
    {
        for (int i = 0; i < n; i++)
            cout << *(symb + i);
        cout << "\n";
    }

    char & operator ()(int i)
    {
        return *(symb + i);
    }

    double chastota (char bukva)
    {
        double k = 0;
        for (int i = 0; i < n; i++)
        {
            if ((*(symb + i)) == bukva) {k++;};
        };
        k = (k/n);
        k *= 100;
        return k;
    }
};


String & operator + (String &A, const String &B)
{
    int k = A.n;
    A.n += B.n;
    char* plagiat = new char [A.n];

    for (int i = 0; i < k; i++)
    {
        *(plagiat + i) = *(A.symb + i);
    };
    for (int i = k; i < A.n; i++)
    {
        *(plagiat + i) = *(B.symb + i - k);
    };

    A.symb = plagiat;
    return A;
}

bool searching (const String &A, const String &B)
{
    if (A.n <= B.n)
    {
        int k = 0;
        for (int i = 0; i < B.n; i++)
        {
            if ((*(A.symb)) == (*(B.symb + i)))
            {
                k++;
                int j = 1;
                while (((*(A.symb + j)) == (*(B.symb + i + j))) && (j < A.n))
                {
                    k++, j++;
                };
            };
            if (k == A.n) {break;}
            else {k = 0;};
        };
        return (k == A.n);
    }
    else
    {
        return false;
    };
}

int main()
{
    String s, l;
    cout << "Enter first string: ";
    s.input();
    cout << s.n;
    cout << "Enter second string: ";
    l.input();
    cout << '\n';

    if (searching(s, l)) {cout << "Yes, the first string is in the second" << '\n';}
    else {cout << "No, the first string isn't in the second" << '\n';};
    cout << '\n';

    cout << "Enter the letter: ";
    char isk;
    cin >> isk;

    cout << "Letter frequency in the first is " << s.chastota(isk) << " %" << '\n';
    cout<< "Letter frequency in the first is " << l.chastota(isk) << " %" << '\n';
    cout << '\n';

    cout << "Concatenation result: ";
    s + l;
    s.output();
    cout << '\n';
}
