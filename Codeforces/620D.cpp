#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll myAbs(ll x) { if (x < 0) return -x; return x; }

struct Pr
{
    ll val;
    int pa, pb;
};

int n, m, nm;
ll a[2000], b[2000], sa, sb, ss;
Pr p[4000000], prtmp;

bool cmp(const Pr& a, const Pr& b)
{
    return a.val < b.val;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a+i), sa += a[i];
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
        scanf("%lld", b+i), sb += b[i];

    ss = sa - sb;
    if (ss == 0)
    {
        printf("0\n0");
        return 0;
    }

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
        p[nm].val = ((a[i] - b[j]) << 1);
        p[nm].pa = i;
        p[nm].pb = j;
        ++nm;
    }

    sort(p, p+nm, cmp);
    prtmp.val = ss;

    int pp = lower_bound(p, p+nm, prtmp, cmp) - p;
    if (pp != nm && p[pp].val == ss)
    {
        printf("0\n1\n%d %d\n", p[pp].pa + 1, p[pp].pb + 1);
        return 0;
    }

    if (n == 1 || m == 1)
    {
        if (pp == nm) --pp;
        if (nm > 1 && pp > 0 && myAbs(ss - p[pp].val) > myAbs(ss - p[pp-1].val)) --pp;
        printf("%lld\n1\n%d %d\n", myAbs(ss - p[pp].val), p[pp].pa + 1, p[pp].pb + 1);
        return 0;
    }

    ll min1 = 2e18, min2 = 2e18;
    int lef, rig, lef1, rig1, lef2, rig2;

    for (int i = 0; i < nm; ++i)
    {
        if (min1 > myAbs(ss - p[i].val))
        {
            min1 = myAbs(ss - p[i].val);
            lef = p[i].pa + 1;
            rig = p[i].pb + 1;
        }

        prtmp.val = ss - p[i].val;
        int j = lower_bound(p, p+nm, prtmp, cmp) - p;

        if (j < nm)
        {
            int jj = j;
            while (jj < nm && (p[jj].pa == p[i].pa || p[jj].pb == p[i].pb)) ++jj;
            if (jj != nm && min2 > myAbs(ss - p[i].val - p[jj].val))
            {
                min2 = myAbs(ss - p[i].val - p[jj].val);
                lef1 = p[i].pa + 1, rig1 = p[i].pb + 1;
                lef2 = p[jj].pa + 1, rig2 = p[jj].pb + 1;
            }
        }

        int jj = j - 1;
        while (jj >= 0 && (p[jj].pa == p[i].pa || p[jj].pb == p[i].pb)) --jj;
        if (jj >= 0 && min2 > myAbs(ss - p[i].val - p[jj].val))
        {
            min2 = myAbs(ss - p[i].val - p[jj].val);
            lef1 = p[i].pa + 1, rig1 = p[i].pb + 1;
            lef2 = p[jj].pa + 1, rig2 = p[jj].pb + 1;
        }
    }

    if (min1 <= min2)
        printf("%lld\n1\n%d %d\n", min1, lef, rig);
    else
        printf("%lld\n2\n%d %d\n%d %d\n", min2, lef1, rig1, lef2, rig2);

    return 0;
}
