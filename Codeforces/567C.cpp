#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> cnt1, cnt2;
int n, k;
ll a[200010];
ll res;

int main()
{
    scanf("%d %d", &n, &k);

    if (n < 3)
    {
        printf("0");
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        ++cnt1[a[i]];
    }

    --cnt1[a[n]];

    for (int i = n-1; i > 0; --i)
    {
        --cnt1[a[i]];
        ++cnt2[a[i+1]];

        if (a[i] % k == 0)
            res += cnt2[a[i]*k] * cnt1[a[i]/k];
    }

    printf("%lld", res);
    return 0;
}
