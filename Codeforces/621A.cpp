#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 2e18;

int n;
ll a, sum, mn;

int main()
{
    scanf("%d", &n);
    mn = INF;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a);
        sum += a;
        if (a&1)
            mn = min(a, mn);
    }

    if (sum&1)
        printf("%lld", sum - mn);
    else
        printf("%lld", sum);
    return 0;
}
