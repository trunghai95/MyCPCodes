#include <bits/stdc++.h>

using namespace std;

int test, n;
string s1, s2;
int dp1[100010], dp2[100010], cnt1[100010], cnt2[100010];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("D:\\boomerang_decoration.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> test;

    for (int tt = 1; tt <= test; ++tt)
    {
        cin >> n >> s1 >> s2;
        if (s1 == s2)
        {
            printf("Case #%d: 0\n", tt);
            continue;
        }

        cnt1[0] = 1;
        for (int i = 1; i < n; ++i)
            cnt1[i] = cnt1[i-1] + (s2[i] != s2[i-1]);
        cnt2[n-1] = 1;
        for (int i = n-2; i >= 0; --i)
            cnt2[i] = cnt2[i+1] + (s2[i] != s2[i+1]);

        dp1[0] = (s1[0] != s2[0]);
        for (int i = 1; i < n; ++i)
            dp1[i] = (s1[i] == s2[i] ? dp1[i-1] : cnt1[i]);
        dp2[n-1] = (s1[n-1] != s2[n-1]);
        for (int i = n-2; i >= 0; --i)
            dp2[i] = (s1[i] == s2[i] ? dp2[i+1] : cnt2[i]);

        int res = min(dp2[0], dp1[n-1]);
        for (int i = 1; i < n; ++i)
        {
            int tmp = max(dp1[i-1], dp2[i]);
            res = min(tmp, res);
        }

        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
