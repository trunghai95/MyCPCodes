#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair<long long,long long> pii;

bool cmp(pii x, pii y)
{
    return x.S < y.S;
}

const long long MAX = 30000;
long long n;
pii a[10000];
long long bit[MAX+1], f[10001];

void update(long long x)
{
    while (x <= MAX)
    {
        ++bit[x];
        x += x&(-x);
    }
}

long long get(long long x)
{
    long long res = 0;
    while (x > 0)
    {
        res += bit[x];
        x -= x&(-x);
    }
    return res;
}

int main()
{
    scanf("%lld", &n);
    for (long long i = 1; i <= n; ++i)
        scanf("%lld %lld", &a[i].F, &a[i].S);
    sort(a+1, a+n+1, cmp);
    memset(bit, 0, sizeof(bit));
    f[1] = a[1].S - a[1].F;
    update(a[1].S);
    for (long long i = 2; i <= n; ++i)
    {
        long long pos = get(a[i].F);
        f[i] = max(f[i-1], f[pos] + a[i].S - a[i].F);
        update(a[i].S);
    }

    printf("%lld", f[n]);
    return 0;
}
