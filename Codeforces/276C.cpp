#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5;
ll bit[MAXN+1], a[MAXN+1];
int n, q;

ll get(int x)
{
    ll res = 0;
    while (x <= MAXN)
    {
        res += bit[x];
        x += x&(-x);
    }

    return res;
}

void update(int x, ll val)
{
    while (x)
    {
        bit[x] += val;
        x -= x&(-x);
    }
}

int main()
{
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; ++i)
        scanf("%lld", a+i);
    sort(a+1, a+1+n);

    for (int i = 0, l, r; i < q; ++i)
    {
        scanf("%d %d", &l, &r);
        update(r, 1);
        update(l-1, -1);
    }

    ll cnt[MAXN+1];
    for (int i = 1; i <= n; ++i)
        cnt[i] = get(i);
    sort(cnt+1, cnt+1+n);

    ll res = 0;
    for (int i = 1; i <= n; ++i)
        res += cnt[i]*a[i];

    printf("%lld", res);
    return 0;
}
