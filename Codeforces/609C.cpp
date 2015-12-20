#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll m[100010], sum;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", m+i), sum += m[i];

    ll tmp = sum / n;
    int cnt = sum - (tmp * n);
    cnt = n - cnt;

    ll res = 0;
    sort(m+1, m+1+n);

    for (int i = 1; i <= cnt; ++i)
    {
        res += abs(m[i] - tmp);
    }
    ++tmp;
    for (int i = cnt + 1; i <= n; ++i)
    {
        res += abs(m[i] - tmp);
    }

    printf("%lld", res >> 1LL);
    return 0;
}
