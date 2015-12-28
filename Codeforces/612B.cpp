#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll p[200010];

int main()
{
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        p[x] = i;
    }
    ll res = 0;
    for (int i = 2; i <= n; ++i)
    {
        res += abs(p[i] - p[i-1]);
    }

    printf("%lld", res);
    return 0;
}
