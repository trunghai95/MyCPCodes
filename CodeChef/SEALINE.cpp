#include <bits/stdc++.h>

using namespace std;

int n, x, test, id[111];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> test;

    while (test--)
    {
        memset(id, 0, sizeof(id));
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            int pos = id[x];
            res += min(pos, i - pos);

            for (int j = 1; j <= i; ++j)
            {
                if (id[j] > pos)
                    ++id[j];
            }

            id[i+1] = pos + 1;
        }
        cout << res << '\n';
    }
    return 0;
}
