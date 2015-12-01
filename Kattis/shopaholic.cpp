#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a[200000];

bool cmp(const ll& x, const ll& y) { return x > y; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a+i);

    sort(a, a+n, cmp);

    ll res = 0;
    for (int i = 2; i < n; i += 3)
        res += a[i];

    printf("%lld", res);
    return 0;
}
