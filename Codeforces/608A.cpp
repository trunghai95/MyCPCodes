#include <bits/stdc++.h>

using namespace std;

int n, s;
int t[1001];

int main()
{
    cin >> n >> s;
    for (int i = 0, u, v; i < n; ++i)
    {
        cin >> u >> v;
        t[u] = max(t[u], v);
    }
    int res = 0;
    while (s)
    {
        res = max(res, t[s]);
        --s, ++res;
    }

    cout << res;
    return 0;
}
