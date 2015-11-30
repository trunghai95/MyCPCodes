#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, w;
    Edge(int x, int y, int z): u(x), v(y), w(z) {}
};

bool cmp(Edge x, Edge y) { return x.w > y.w; }

int n, nn, w;
vector<Edge> e;
bool ck[810];
int res[810];

int main()
{
    scanf("%d", &n);
    memset(ck, 0, sizeof(ck));
    nn = n*2;
    for (int u = 2; u <= nn; ++u)
        for (int v = 1; v < u; ++v)
        {
            scanf("%d", &w);
            e.push_back(Edge(u,v,w));
        }
    sort(e.begin(), e.end(), cmp);
    for (int i = 0; i < e.size(); ++i)
    if (!ck[e[i].u] && !ck[e[i].v])
    {
        res[e[i].u] = e[i].v;
        res[e[i].v] = e[i].u;
        ck[e[i].u] = ck[e[i].v] = 1;
    }

    for (int i = 1; i <= nn; ++i)
        printf("%d ", res[i]);
    return 0;
}
