#include <bits/stdc++.h>

using namespace std;

int n, k, c[32][32];

bool ck()
{
    if (!n && k == 1) return 1;

    int nn = n;
    int sum = 0;
    while (nn)
    {
        sum += !(nn&1);
        nn >>= 1;
    }

    return (sum == k);
}

int main()
{
    c[0][0] = 1;
    for (int i = 1; i <= 31; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }

    cin >> n >> k;
    int res = (k == 1);
    int bit = 1 + floor(log(n) / log(2));

    for (int i = 1; i < bit; ++i)
        res += c[i-1][k];

    n = n - (1 << (bit - 1));
    int newbit = 1 + floor(log(n) / log(2));
    k -= bit - newbit - 1;
    bit = newbit;

    while (n)
    {
        for (int i = 1; i <= bit; ++i)
            res += (k < bit - i) ? 0 : c[i - 1][k - bit + i];

        n = n - (1 << (bit - 1));
        int newbit = 1 + floor(log(n) / log(2));
        k -= bit - newbit - 1;
        bit = newbit;
    }

    cout << res;
    return 0;
}
