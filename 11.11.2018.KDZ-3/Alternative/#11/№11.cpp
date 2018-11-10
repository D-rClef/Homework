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
   char* symb;

    void input ()
    {
        gets(symb);
    }

    void output()
    {
        int n = Length(symb);
        for (int i = 0; i < n; i++)
            cout << *(symb + i);
        cout << "\n";
    }

    char & operator ()(int i)
    {
        return *(symb+i);
    }

    double chastota (char bukva)
    {
        int n = Length(symb);
        double k = 0;
        for (int i = 0; i < n; i++)
        {
            if (*(symb + i) == bukva) {k++;};
        };
        k = (k/n);
        k *= 100;
        return k;
    }

    int size_ (String &A)
    {
        return Length(A.symb);
    }
};


String & operator + (String &A, const String &B)
{
    int k = Length(A.symb);
    k += Length(B.symb);

    char* plagiat = new char [k];

    for (int i = 0; i < Length(A.symb); i++)
    {
        *(plagiat + i) = *(A.symb + i);
    };
    for (int i = Length(A.symb); i < k; i++)
    {
        *(plagiat + i) = *(B.symb + i - Length(A.symb));
    };

    A.symb = plagiat;
    return A;
}

bool searching (const String &A, const String &B)
{
    if (Length(A.symb) <= Length(B.symb))
    {
        int k = 0;
        for (int i = 0; i < Length(B.symb); i++)
        {
            if ((*(A.symb)) == (*(B.symb + i)))
            {
                k++;
                int j = 1;
                while (((*(A.symb + j)) == (*(B.symb + i + j))) && (j < Length(A.symb)))
                {
                    k++, j++;
                };
            };
            if (k == Length(A.symb)) {break;}
            else {k = 0;};
        };
        return (k == Length(A.symb));
    }
    else
    {
        return (0 == 1);
    };
}

int main()
{
    String s, l;
    s.input();
    l.input();
    cout << '\n';
    s.output();
    l.output();
    cout << '\n';
    //cout << s(0) << " " << l(m-1) << '\n' << '\n';

    if (searching(s, l) == 1) {cout << "Yes" << '\n';}
    else {cout << "No" << '\n';};

    cout << '\n';
    s + l;
    s.output();

    cout << '\n';

    char isk;
    cin >> isk;

    cout << s.chastota(isk) << "%" << '\n';
    cout<< l.chastota(isk);
}
