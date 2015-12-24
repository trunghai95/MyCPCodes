#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<int> row, col;
ll n, q, x;
char c[5];

int main()
{
    freopen("adjustment.in", "r", stdin);
    freopen("adjustment.out", "w", stdout);
    scanf("%lld %lld", &n, &q);
    ll sumr1, sumc1;
    sumr1 = sumc1 = n*(n+1)/2 + n;

    for (ll i = 0; i < q; ++i)
    {
        scanf("%s %lld", &c, &x);
        if (c[0] == 'R')
        {
            if (row.find(x) != row.end())
                printf("0\n");
            else
            {
                ll res = sumr1 + (x - 1)*(n - col.size());
                printf("%lld\n", res);
                sumc1 -= x + 1;
                row.insert(x);
            }
        }
        else
        {
            if (col.find(x) != col.end())
                printf("0\n");
            else
            {
                ll res = sumc1 + (x - 1)*(n - row.size());
                printf("%lld\n", res);
                sumr1 -= x + 1;
                col.insert(x);
            }
        }
    }

    return 0;
}
