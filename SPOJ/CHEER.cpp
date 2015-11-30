#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge
{
    int u, v, w;
};

bool cmp(const Edge& x, const Edge& y)
{
    return x.w < y.w;
}

const int MAXN = 10000;
const int MAXE = 100000;
Edge e[MAXE + 1];
int c[MAXN + 1], n, p;
bool ck[MAXN + 1];

int main()
{
    scanf("%d %d", &n, &p);
    int minc = 2e9;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", c+i);
        minc = min(minc, c[i]);
    }

    for (int i = 1; i <= p; ++i)
    {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
        e[i].w = e[i].w * 2 + c[e[i].u] + c[e[i].v];
    }

    sort(e+1, e+1+p, cmp);
    int res = minc;
    int cnt = 0;
    for (int i = 1; i <= p && cnt < n-1; ++i)
    {
        if (ck[e[i].u] && ck[e[i].v])
            continue;

        ck[e[i].u] = ck[e[i].v] = true;
        ++cnt;
        res += e[i].w;
    }

    printf("%d", res);
    return 0;
}
