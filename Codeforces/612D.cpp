#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, k;
pii pnt[2000010];
vector<pii> res;

int main()
{
    scanf("%d %d", &n, &k);

    for (int i = 0, u, v; i < n; ++i)
    {
        scanf("%d %d", &u, &v);
        pnt[i << 1] = pii(u, 0);
        pnt[(i << 1) | 1] = pii(v, 1);
    }

    n <<= 1;
    sort(pnt, pnt+n);

    int cnt = 0, l = -1;
    for (int i = 0; i < n; ++i)
    {
        if (pnt[i].second)
        {
            if (cnt == k)
            {
                res.push_back(pii(l, pnt[i].first));
            }
            --cnt;
        }
        else
        {
            ++cnt;
            if (cnt == k)
                l = pnt[i].first;
        }
    }

    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); ++i)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}
