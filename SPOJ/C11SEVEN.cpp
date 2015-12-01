#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
const ll MODD = 1e9 + 7;

struct Node
{
    ll val[7];
    int sz;
};

Node it[MAXN*4 + 1];
ll a[MAXN + 1];
int n, m;

void itinit(int p, int lef, int rig)
{
    if (lef == rig)
    {
        for (int i = 1; i < 7; ++i)
            it[p].val[i] = 1;
        it[p].val[0] = a[lef];
        it[p].sz = 1;
        return;
    }

    int mid = (lef + rig) >> 1;
    int lc = p << 1, rc = lc + 1;
    itinit(lc, lef, mid);
    itinit(rc, mid + 1, rig);

    it[p].sz = it[lc].sz + it[rc].sz;
    for (int i = 0; i < 7; ++i)
        it[p].val[i] = it[lc].val[i] * it[rc].val[(i - (it[lc].sz % 7) + 7) % 7] % MODD;
}

void del(int p, int pos)
{
    if (it[p].sz == 1)
    {
        it[p].sz = 0;
        for (int i = 0; i < 7; ++i)
            it[p].val[i] = 1;
        return;
    }

    int lc = p << 1, rc = lc + 1;

    if (pos >= it[lc].sz)
        del(rc, pos - it[lc].sz);
    else
        del(lc, pos);

    it[p].sz = it[lc].sz + it[rc].sz;
    for (int i = 0; i < 7; ++i)
        it[p].val[i] = it[lc].val[i] * it[rc].val[(i - (it[lc].sz % 7) + 7) % 7] % MODD;
}

void update(int p, int pos, ll val)
{
    if (it[p].sz == 1)
    {
        for (int i = 1; i < 7; ++i)
            it[p].val[i] = 1;
        it[p].val[0] = val;
        return;
    }

    int lc = p << 1, rc = lc + 1;

    if (pos >= it[lc].sz)
        update(rc, pos - it[lc].sz, val);
    else
        update(lc, pos, val);

    it[p].sz = it[lc].sz + it[rc].sz;
    for (int i = 0; i < 7; ++i)
        it[p].val[i] = it[lc].val[i] * it[rc].val[(i - (it[lc].sz % 7) + 7) % 7] % MODD;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
        scanf("%lld", a+i);

    itinit(1, 0, n-1);

    for (int i = 0; i < m; ++i)
    {
        int type, k;
        ll v;
        scanf("%d %d", &type, &k);

        if (type == 1)
            del(1, k);
        else if (type == 2)
        {
            scanf("%lld", &v);
            update(1, k, v);
        }
        else
            printf("%lld\n", it[1].val[k]);
    }
    return 0;
}
