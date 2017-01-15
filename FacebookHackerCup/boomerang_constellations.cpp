#include <bits/stdc++.h>

using namespace std;

int test, n, x[2001], y[2001];

int dist(int p1, int p2)
{
    return (x[p1] - x[p2])*(x[p1] - x[p2]) + (y[p1] - y[p2])*(y[p1] - y[p2]);
}

int main()
{
    //freopen("boomerang_constellations.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
    {
        scanf("%d", &n);
        vector<int> v[2001];

        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", x+i, y+i);

            for (int j = 0; j < i; ++j)
            {
                int d = dist(i, j);
                v[i].push_back(d);
                v[j].push_back(d);
            }
        }

        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            sort(v[i].begin(), v[i].end());
            int lef = 0, rig = 0;
            for (int j = 1; j < v[i].size(); ++j)
            {
                if (v[i][j] != v[i][j-1])
                {
                    res += (rig - lef + 1)*(rig - lef)/2;
                    lef = j;
                }
                rig = j;
            }

            res += (rig - lef + 1)*(rig - lef)/2;
        }

        printf("Case #%d: %d\n", tt, res);
    }

    return 0;
}
