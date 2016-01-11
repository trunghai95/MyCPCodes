// Brute-force, 25/100

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll MODD = 1e9 + 7;

int test, n, m;
bool e[11][11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> test;

    while (test--)
    {
        memset(e, 0, sizeof(e));
        cin >> n >> m;

        for (int i = 0, u, v; i < m; ++i)
        {
            cin >> u >> v;
            e[u][v] = e[v][u] = true;
        }

        vector<int> per;
        for (int i = 1; i <= n; ++i)
            per.push_back(i);

        ll res = 0;

        do
        {
            bool f = true;
            for (int i = 1; i < per.size() && f; ++i)
            {
                if (e[per[i]][per[i-1]])
                {
                    f = false;
                    break;
                }
            }
            if (f) res = (res + 1) % MODD;
        }
        while (next_permutation(per.begin(), per.end()));

        cout << res << '\n';
    }
    return 0;
}
