#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (!a || !b) return a | b;
    return gcd(b%a, a);
}

struct PhanSo
{
    ll tu, mau;
    PhanSo() {}
    PhanSo(ll t, ll m): tu(t), mau(m)
    {
        if (tu == 0) { mau = 1; return; }

        if (tu < 0) tu = -tu, mau = -mau;

        ll g = gcd(tu, abs(mau));
        tu /= g;
        mau /= g;
    }
};

bool operator<(const PhanSo& x, const PhanSo& y)
{
    return x.tu * y.mau < x.mau * y.tu;
}

struct Line
{
    ll a, b;
    PhanSo c;
};

bool cmp(const Line& x, const Line& y)
{
    if (x.a == y.a)
    {
        if (x.b == y.b)
            return x.c < y.c;
        return x.b < y.b;
    }

    return x.a < y.a;
}

const int MAXN = 1e5;
int test, n;
Line ln[MAXN + 1];

int main()
{
    //freopen("in.txt", "r", stdin);
    ln[0].a = ln[0].b = -1e18;
    scanf("%d", &test);

    while (test--)
    {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i)
        {
            ll c, cmau = 1;
            scanf("%lld %lld %lld", &ln[i].a, &ln[i].b, &c);

            if (ln[i].a < 0)
            {
                ln[i].a = -ln[i].a; ln[i].b = -ln[i].b; c = -c;
            }

            if (!ln[i].a)
            {
                cmau = ln[i].b; ln[i].b = 1;
            }
            else if (!ln[i].b)
            {
                cmau = ln[i].a; ln[i].a = 1;
            }
            else
            {
                ll g = gcd(ln[i].a, abs(ln[i].b));
                ln[i].a /= g; ln[i].b /= g; cmau = g;
            }

            ln[i].c = PhanSo(c, cmau);
        }

        sort(ln + 1, ln+1+n, cmp);
        int res = 0, cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (ln[i].a != ln[i-1].a || ln[i].b != ln[i-1].b)
            {
                res = max(res, cnt);
                cnt = 1;
            }
            else
            {
                if (ln[i].c.tu != ln[i-1].c.tu || ln[i].c.mau != ln[i-1].c.mau)
                    ++cnt;
            }
        }

        res = max(res, cnt);

        printf("%d\n", res);
    }
    return 0;
}
