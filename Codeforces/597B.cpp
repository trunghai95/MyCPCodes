#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair<int,int> pii;
const int MAXN = 5e5;
int n, f[MAXN+1];
pii order[MAXN+1];

bool cmp(const pii& x, const pii& y)
{
    return x.S < y.S;
}

int tknp(int p, int x)
{
    int l = 1, r = p;

    while (l < r)
    {
        int m = (l + r) / 2;
        if (order[m].S < x)
            l = m+1;
        else
            r = m;
    }

    return l;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &order[i].F, &order[i].S);
    }

    sort(order+1, order+1+n, cmp);
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        int pos = tknp(i, order[i].F) - 1;
        f[i] = max(f[i-1], f[pos] + 1);
    }

    printf("%d", f[n]);
    return 0;
}
