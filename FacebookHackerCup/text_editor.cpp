#include <bits/stdc++.h>

using namespace std;

int test, n, k, f[301][301];
string s[301];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("text_editor.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> test;

    for (int tt = 1; tt <= test; ++tt)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            cin >> s[i];

        sort(s+1, s+1+n);
        memset(f, -1, sizeof(f));

        for (int i = 1; i <= n; ++i)
        {
            f[i][1] = s[i].length();

            for (int j = 1; j < i; ++j)
            {
                int dis = 0;
                while (dis < s[i].length() && dis < s[j].length() && s[i][dis] == s[j][dis])
                    ++dis;
                dis = (s[i].length() - dis) + (s[j].length() - dis);

                for (int h = min(j, k - 1); h >= 1; --h)
                {
                    f[i][h+1] = (f[i][h+1] == -1) ? f[j][h] + dis : min(f[j][h] + dis, f[i][h+1]);
                }
            }
        }

        int res = 2e9;
        for (int i = k; i <= n; ++i)
            res = min(res, f[i][k] + (int)s[i].length());
        res += k;
        cout << "Case #" << tt << ": " << res << '\n';
    }
    return 0;
}
