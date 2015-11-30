#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, k;
ll a[200010], x, res, l[200010], r[200010];

int main()
{
    res = 0;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    l[0] = r[n+1] = 0;
    for (int i = 1; i <= n; ++i)
        l[i] = l[i-1] | a[i];
    for (int i = n; i >= 1; --i)
        r[i] = r[i+1] | a[i];
    res = r[1];
    for (int i = 1; i <= n; ++i)
    {
        ll tmp = a[i];
        for (int j = 0; j < k; ++j) tmp *= x;
        res = max(res, l[i-1] | tmp | r[i+1]);
    }
    cout << res;
    return 0;
}
