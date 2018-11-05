#include <iostream>

using namespace std;

struct String
{
   int n;
   char* symb;

   String (int a)
   {
       n = a;
       symb = new char [a];
   };

   String (const String & A)
    {
        n = A.n;
        symb = A.symb;
    };

    ~String ()
    {
        delete[]symb;
    };

    void input ()
    {
        for (int i = 0; i < n; i++)
            cin >> *(symb + i);
    }

    void output()
    {
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
        double k = 0;
        for (int i = 0; i < n; i++)
        {
            if (*(symb + i) == bukva) {k++;};
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
        return (0 == 1);
    };
}

int main()
{
    int n, m;
    cin >> n >> m;
    char isk;
    cin >> isk;

    String s(n), l(m);
    s.input();
    l.input();
    cout << '\n';
    s.output();
    l.output();
    cout << '\n';
    cout << s(0) << " " << l(m-1) << '\n' << '\n';

    if (searching(s, l) == 1) {cout << "Yes" << '\n';}
    else {cout << "No" << '\n';};

    cout << '\n';
    s + l;
    s.output();

    cout << '\n';

    cout << s.chastota(isk) << "%";
    cout<< '\n';
}
