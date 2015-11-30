#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 100000;
const int modd = 1e9 + 7;
int n, k;
int a[MAXN], b, lt[10];

int main()
{
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    lt[0] = 1;
    for (int i = 1; i < 10; ++i)
        lt[i] = lt[i-1] * 10;

    cin >> n >> k;

    for (int i = 0; i < n/k; ++i)
        cin >> a[i];

    ll res = 1;
    for (int i = 0; i < n/k; ++i)
    {
        cin >> b;

        ll cnt = (lt[k] - 1) / a[i] + 1;
        ll tmp = b * lt[k-1];
        ll l = tmp - (tmp % a[i]) + a[i] * (tmp % a[i] != 0);
        tmp = (b + 1) * lt[k-1] - 1;
        ll r = tmp - (tmp % a[i]);
        if (l <= r)
            cnt -= (r - l) / a[i] + 1;
        res = (res * cnt) % modd;
    }

    cout << res;
    return 0;
}
