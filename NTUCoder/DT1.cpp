#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m;
ll a[101][101];
pii prev[101][101];
vector<pii> res;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
        cin >> a[i][j];
    }

    for (int i = 2; i <= m; ++i)
        a[1][i] += a[1][i-1], prev[1][i] = pii(1, i-1);

    for (int i = 2; i < n; ++i)
    for (int j = 1; j <= m; ++j)
        a[i][j] += max(a[i-1][j], a[i][j-1]), prev[i][j] = (a[i-1][j] > a[i][j-1] ? pii(i-1,j) : pii(i, j-1));

    ll mx = a[n][1] + a[n-1][1];
    int mxpos = 1;
    for (int i = 2; i <= m; ++i)
    {
        if (mx < a[n][i] + a[n-1][i])
            mx = a[n][i] + a[n-1][i], mxpos = i;
    }

    res.push_back(pii(n, mxpos));
    res.push_back(pii(n-1, mxpos));
    int f = n-1, s = mxpos;
    while (f != 1 || s != 1)
    {
        res.push_back(prev[f][s]);
        f = res.back().first;
        s = res.back().second;
    }

    cout << mx << '\n';
    for (int i = res.size() - 1; i >= 0; --i)
        cout << '(' << res[i].first << ',' << res[i].second << ')' << '\n';
    return 0;
}
