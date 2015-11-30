#include <bits/stdc++.h>

using namespace std;

int n, k, cnt[200];

int main()
{
    cin >> n >> k;
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        ++cnt[x];
    }

    int res = 0;
    for (int i = 1; i <= k; ++i)
    {
        res += abs(cnt[i] - n/k);
    }
    cout << res/2;
    return 0;
}
