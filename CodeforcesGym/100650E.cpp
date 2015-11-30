#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, w;
};

bool cmp(const Edge &x, const Edge &y) { return x.w < y.w; }

Edge e[50];
int deg[50];
int n, m;

int main()
{
    freopen("in.txt", "r", stdin);
    int test = 0;
    while (++test)
    {
        cin >> n >> m;
        if (!n && !m) return 0;

        memset(deg, 0, sizeof(deg));

        for (int i = 0; i < m; ++i)
        {
            cin >> e[i].u >> e[i].v >> e[i].w;
        }
        sort(e, e+m, cmp);

        int res = 0, cnt;

        for (int i = 0; i < m; ++i)
        {
            if (deg[e[i].u] < 2 && deg[e[i].v] < 2)
            {
                ++deg[e[i].u];
                ++deg[e[i].v];
                ++cnt;
                res += e[i].w;
            }
        }

        if (cnt == n)
            cout << "The minimal cost for test case " << test << " is " << res << ".\n";

        else
            cout << "There is no reliable net possible for test case " << test << ".\n";
    }
    return 0;
}
