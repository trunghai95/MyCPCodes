#include <bits/stdc++.h>

using namespace std;

int n, m, cnt[50];

int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

    bool first = true;
	while (cin >> n >> m)
    {
        if (!first)
            cout << '\n';
        else first = false;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ++cnt[i+j];

        int mx = 0;

        for (int i = 1; i <= n + m; ++i)
            mx = max(mx, cnt[i]);

        for (int i = 1; i <= n+m; ++i)
            if (cnt[i] == mx)
                cout << i << '\n';
    }

    return 0;
}
