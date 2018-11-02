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

    String & operator += (const String & A)
    {
        int k = n;
        n += A.n;
        char* R = new char [n];
        for (int i = 0; i < n; i++)
        {
            if (i < k)
            {
                *(R+i) = *(symb+i);
            }
            else
            {
                *(R+i) = *(symb+i-k);
            };
        };

        delete [] symb;
        symb = new char [n];
        for (int i = 0; i < n; i++)
        {
            *(symb + i) = *(R + i);
        };
        delete[]R;
        return *this;
    }

};

    String & operator + ( String &A, const String &B)
    {
        return A += B;
    }

int main()
{
    int n, m;
    cin >> n >> m;
   String s(n), l(m);
   s.input();
   l.input();
   cout << '\n';
   s.output();
   l.output();
   cout << '\n';
   cout << s(0) << l(m-1) << '\n';

   s + l;


}
