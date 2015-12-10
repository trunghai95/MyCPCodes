#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;

char s[15];
int test, n;
ll cnt[2000], pw2[100001];
vector<int> a;
ll dp[1024][1024];

void init()
{
    pw2[0] = 1;
    for (int i = 1; i <= 100000; ++i)
    {
        pw2[i] = (pw2[i-1] << 1) % MODD;
    }
}

int ff()
{
    int res = 0;
    for (int i = 0; i < 10; ++i)
        res += pw2[i] * (s[i] == '+');
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    init();
    scanf("%d", &test);

    while (test--)
    {
        scanf("%s %d", s, &n);
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        a.clear();
        int goal = 0;
        for (int i = 0; i < 10; ++i)
            goal += pw2[i] * (s[i] == 'w');

        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s);
            int tmp = ff();
            if (tmp && !cnt[tmp]) a.push_back(tmp);
            ++cnt[tmp];
        }

        if (a.empty())
        {
            if (goal)
                printf("0\n");
            else
                printf("%lld\n", pw2[cnt[0]]);
            continue;
        }

        dp[1][a[0]] = 1;
        dp[1][0] = 1;
        for (int i = 1; i < a.size(); ++i)
        {
            for (int j = 0; j < 1024; ++j)
                dp[i+1][j] = (dp[i][j] + dp[i][j ^ a[i]]) % MODD;
        }

        ll res = pw2[cnt[0]];
        for (int i = 0; i < a.size(); ++i)
            res = (res * pw2[cnt[a[i]] - 1]) % MODD;
        res = (res * dp[a.size()][goal]) % MODD;
        printf("%lld\n", res);
    }
    return 0;
}
