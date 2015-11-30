#include <bits/stdc++.h>

using namespace std;

int n, t[1000], s[1000], f[1000];

bool meet(int i, int j)
{
    if (min(s[i],f[i]) > max(s[j],f[j]) || max(s[i],f[i]) < min(s[j],f[j])) return 0;

    if (s[i] > f[i] && s[j] > f[j])
        return (s[i] + t[i] == s[j] + t[j]);

    if (s[i] < f[i] && s[j] < f[j])
        return (s[i] - t[i] == s[j] - t[j]);

    if (s[i] < f[i]) swap(i,j);

    if (s[i] <= f[j] && f[i] >= s[j])
        return (t[j] + f[i] - s[j] <= t[i] + s[i] - f[i]) && (t[j] + s[i] - s[j] >= t[i]);

    if (s[i] >= f[j] && f[i] <= s[j])
        return (t[i] + s[i] - f[j] <= t[j] + f[j] - s[j]) && (t[i] + s[i] - s[j] >= t[j]);

    if (s[i] >= s[j] && s[i] <= f[j])
        return (t[i] + s[i] - s[j] >= t[j] && t[j] + s[i] - s[j] >= t[i]);

    if (f[i] >= s[j] && f[i] <= f[j])
        return (t[i] + s[i] - f[j] <= t[j] + f[j] - s[j]) && (t[j] + f[i] - s[j] <= t[i] + s[i] - f[i]);

    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t[i] >> s[i] >> f[i];

    for (int i = 0; i < n; ++i)
    {
        int res = 0;
        for (int j = 0; j < n; ++j)
        if (j != i)
        {
            res += meet(i, j);
        }

        cout << res << ' ';
    }
    return 0;
}
