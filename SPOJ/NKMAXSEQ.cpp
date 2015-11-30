#include <bits/stdc++.h>

using namespace std;

const int MAX = 50001;
int n, a[MAX], sum[MAX], p, res;

int main()
{
    //freopen("in.txt", "r", stdin);
    a[0] = sum[0] = 0;
    cin >> n >> p;
    res = 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        int s = sum[i] = sum[i-1] + a[i], len = i;
        while (s < p && len)
        {
            s -= a[i - len + 1];
            --len;
        }
        res = max(res, len);
    }
    if (res) cout << res;
    else cout << -1;
    return 0;
}
