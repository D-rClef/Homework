#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

struct rational
{
    int m;
    int n;

    rational(int a, int b)
    {
        m = a / gcd(a, b);
        n = b / gcd(a, b);
        if (n < 0)
        {
            n = -n;
            m = -m;
        };
    }

    rational(int a)
    {
        m = a;
        n = 1;
    }

    rational()
    {
        m = 0;
        n = 1;
    }

    rational(const rational &A)
    {
        m = A.m;
        n = A.n;
    }

    rational & operator = (const rational &A)
    {
        m = A.m;
        n = A.n;
        return *this;
    }

    rational & operator *= (const rational &A)
    {
        m *= A.m;
        n *= A.n;
        int d = gcd(m, n);
        m /= d;
        n /= d;
        return *this;
    }

    rational & operator /= (const rational &A)
    {
        m *= A.n;
        n *= A.m;
        int d = gcd(m, n);
        m /= d;
        n /= d;
        return *this;
    }

    rational & operator += (const rational &A)
    {
        m = ((m * A.n) + (n * A.m));
        n *= A.n;
        int d = gcd(m, n);
        m /= d;
        n /= d;
        return *this;
    }

    rational & operator -=(const rational &A)
    {
        m = ((m * A.n) - (n * A.m));
        n *= A.n;
        int d = gcd(m, n);
        m /= d;
        n /= d;
        if (n < 0)
        {
            n = -n;
            m = -m;
        };
        return *this;
    }
};

rational & operator + ( rational A, const rational &B)
{
    return A += B;
}

rational & operator -( rational A, const rational &B)
{
    return A -= B;
}

rational & operator * ( rational A, const rational &B)
{
    return A *= B;
}

rational & operator / ( rational A, const rational &B)
{
    return A /= B;
}

bool operator ==(const rational &A, const rational &B)
{
    return ((A.m == B.m) && (A.n == B.n));
}

bool operator != (const rational &A, const rational &B)
{
    return !(A == B);
}

bool operator > (const rational &A, const rational &B)
{
    return (((A.m*B.n) - (B.m*A.n) > 0) && (A.n*B.n > 0)) || (((A.m*B.n) - (B.m*A.n) < 0) && (A.n*B.n < 0));
}

bool operator < (const rational &A, const rational &B)
{
    return (((A.m*B.n) - (B.m*A.n) < 0) && (A.n*B.n > 0)) || (((A.m*B.n) - (B.m*A.n) > 0) && (A.n*B.n < 0));
}

bool operator >= (const rational &A, const rational &B)
{
    return !(A < B);
}

bool operator <= (const rational &A, const rational &B)
{
    return !(A > B);
}

std::istream & operator >> (std::istream &is, rational &A)
{
    is >> A.m >> A.n;
    int d = gcd(A.m, A.n);
    A.m /= d;
    A.n /= d;
    return is;
}

std::ostream & operator << (std::ostream &os, const rational &A)
{
    os << A.m << "/" << A.n;
    return os;
}

int main() {
	int argh1,argh2,argh3, argh4;
	cin >> argh1 >> argh2 >> argh3 >>argh4;
	cout << "\n";

    rational A(argh1, argh2), B(argh3, argh4);
    cout << "A = " << A << "\n" << "B = " << B << "\n";
    cout << "\n";

    cout << "A + B = " << A + B << "\n";
    cout << "A - B = " << A - B << "\n";
    cout << "A * B = " << A * B << "\n";
    cout << "A / B = " << A / B << "\n";
    cout << "\n";


    if (A==B)
    {
        cout << A << " == " << B << "\n";
    };

    if (A!=B)
    {
        cout << A << " != " << B << "\n";
    };

    if (A > B)
    {
        cout << A << " > " << B << "\n";
    };

    if (A >= B)
    {
        cout << A << " >= " << B << "\n";
    };

    if (A < B)
    {
        cout << A << " < " << B << "\n";
    };

    if (A <= B)
    {
        cout << A << " <= " << B << "\n";
    };

    return 0;
}
