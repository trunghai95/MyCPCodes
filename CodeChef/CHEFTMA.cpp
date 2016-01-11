#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100010;

int test, n, k, m, a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &test);

    while (test--)
    {
        scanf("%d %d %d", &n, &k, &m);
        vector<int> dif, but;
        for (int i = 0; i < n; ++i)
            scanf("%d", a+i);
        for (int i = 0; i < n; ++i)
            scanf("%d", b+i), dif.push_back(a[i] - b[i]);

        for (int i = 0, x; i < k; ++i)
            scanf("%d", &x), but.push_back(x);
        for (int i = 0, x; i < m; ++i)
            scanf("%d", &x), but.push_back(x);

        sort(dif.begin(), dif.end());
        sort(but.begin(), but.end());
        int i = dif.size() - 1, j = but.size() - 1;

        while (i >= 0)
        {
            while (j >= 0 && but[j] > dif[i]) --j;

            if (j < 0) break;

            dif[i] -= but[j];
            --i, --j;
        }

        ll res = 0;

        for (i = 0; i < dif.size(); ++i)
            res += (ll)dif[i];

        printf("%lld\n", res);
    }

    return 0;
}
