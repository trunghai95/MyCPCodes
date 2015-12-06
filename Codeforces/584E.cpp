#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
const int MAXN = 2000;
int id[MAXN+1], p[MAXN+1], pos[MAXN+1], res, n, x;
vector<pii> sq;

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", p+i);
    }

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        id[x] = i;
    }

    for (int i = 1; i <= n; ++i)
        p[i] = id[p[i]], pos[p[i]] = i, res += abs(p[i] - i);
    res >>= 1;

    bool f = false;

    for (int i = n; i > 0; --i)
    {
        if (pos[i] == i) continue;

        for (int j = pos[i] + 1; j <= i; ++j)
        {
            if (p[j] <= pos[i])
            {
                sq.push_back(pii(pos[i], pos[p[j]]));
                int tmp = p[j];
                swap(p[pos[i]], p[j]);
                swap(pos[i], pos[tmp]);
            }
        }
    }

    printf("%d\n%d\n", res, sq.size());

    for (int i = 0; i < sq.size(); ++i)
        printf("%d %d\n", sq[i].first, sq[i].second);

    return 0;
}
