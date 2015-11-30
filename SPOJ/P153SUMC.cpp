#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main()
{
    cin >> a >> b >> n;

    int f[] = {a,b,b-a,-a,-b,a-b};

    cout << f[(n-1)%6];

    return 0;
}
