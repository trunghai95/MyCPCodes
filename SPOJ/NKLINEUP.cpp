#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int n, q, a[50001], x, y;
pii t[200001], tmp;

void ITinit(int k, int l, int r)
{
    if (l == r) t[k].first = t[k].second = l;
    else
    {
        ITinit(k<<1, l, (l+r)>>1);
        ITinit((k<<1)+1, ((l+r)>>1)+1, r);
        pii p1 = t[k<<1], p2 = t[(k<<1)+1];
        t[k].first = (a[p1.first] <= a[p2.first])? p1.first : p2.first;
        t[k].second = (a[p1.second] >= a[p2.second])? p1.second : p2.second;
    }
}

pii ITquery(int k, int l, int r, int x, int y)
{
    if (l > y || r < x) return pii(-1,-1);
    if (l >= x && r <= y) return t[k];
    pii p1 = ITquery(k<<1, l, (l+r)>>1, x, y);
    pii p2 = ITquery((k<<1)+1, ((l+r)>>1)+1, r, x, y);
    if (p1 == pii(-1,-1)) return p2;
    if (p2 == pii(-1,-1)) return p1;
    pii res;
    res.first = (a[p1.first] <= a[p2.first])? p1.first : p2.first;
    res.second = (a[p1.second] >= a[p2.second])? p1.second : p2.second;
    return res;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    ITinit(1, 1, n);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d", &x, &y);
        tmp = ITquery(1, 1, n, x, y);
        printf("%d\n", a[tmp.second] - a[tmp.first]);
    }
    return 0;
}
