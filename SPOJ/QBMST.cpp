#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 10000;
const int MAXM = 15000;

struct Edge
{
    int u, v;
    ll w;
};

bool cmp(const Edge& x, const Edge& y)
{
    return x.w < y.w;
}

Edge e[MAXM];
bool ck[MAXN + 1];
int n, m;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    sort(e, e+m, cmp);
    ll res = 0;
    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        if (ck[e[i].u] && ck[e[i].v])
            continue;

        ck[e[i].u] = ck[e[i].v] = true;
        res += e[i].w;
        ++cnt;
    }

    printf("%lld", res);
    return 0;
}
