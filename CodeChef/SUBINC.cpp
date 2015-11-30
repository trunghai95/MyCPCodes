#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, a[100001];
ll res, cnt[100001];

int main()
{
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int test;
	cin >> test;
	a[0] = 2e9;
	while (test--)
    {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        res = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            cnt[i] = (a[i] < a[i-1])? 1 : (cnt[i-1] + 1);
            if (cnt[i] == 1)
                res += cnt[i-1] * (cnt[i-1] + 1) / 2;
        }

        res += cnt[n] * (cnt[n] + 1) / 2;

        cout << res << endl;
    }

    return 0;
}
