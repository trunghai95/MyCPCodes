#include <bits/stdc++.h>

using namespace std;

int a, b;

bool isPrime(int x)
{
    if (x == 2)
        return 1;
    for (int i = 2; i*i <= x; ++i)
        if (x%i == 0)
            return 0;

    return 1;
}

int main()
{
    cin >> a >> b;

    if (!isPrime(b))
    {
        cout << "NO";
        return 0;
    }

    if (a == 2)
    {
        if (b == 3)
        {
            cout << "YES";
            return 0;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    if ((b-a)&1)
    {
        cout << "NO";
        return 0;
    }

    for (int i = 2; i < b-a; i += 2)
    {
        if (isPrime(a+i))
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
