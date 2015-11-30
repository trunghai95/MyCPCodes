#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;
int n, a[MAX], p[MAX], next;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> p[i];
    }

    int x = 1, res = 0;
    while (1)
    {
        for (next = x; next <= n && p[next] >= p[x]; ++next)
        {
            res += a[next]*p[x];
        }
        x = next;
        if (x > n) break;
    }

    cout << res;

    return 0;
}
