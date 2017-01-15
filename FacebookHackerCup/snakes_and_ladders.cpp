#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;

struct Ladder
{
    int x, h;
};

bool cmp(const Ladder& x, const Ladder& y) { return x.x < y.x; }
bool cmph(const Ladder& x, const Ladder& y) { return x.h < y.h; }

int test, n, cnt[200010];
Ladder lad[200010];
bool ck[200010];
map<int,int> mp;

ll f(vector<int> &v)
{
    if (v.size() <= 1)
        return 0;

    ll res = 0;
    ll sum = 0, sumSqr = 0;
    for (int i = 0; i < v.size(); ++i)
        sum = (sum + v[i]) % MODD;
    for (int i = 0; i < v.size(); ++i)
    {
        sum = (sum - v[i] + MODD * MODD) % MODD;
        res = (res + (((ll)v[i]*v[i]) % MODD)*(v.size() - 1)) % MODD;
        res = (res - (ll)v[i] * sum * 2 + MODD*MODD) % MODD;
    }

    return res;
}

int main()
{
    freopen("D:\\snakes_and_ladders.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt)
    {
        mp.clear();
        ll res = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &lad[i].x, &lad[i].h);

        sort(lad, lad+n, cmph);
        int tmp = 0;
        mp[lad[0].h] = 0;
        for (int i = 1; i < n; ++i)
        if (lad[i].h != lad[i-1].h)
            mp[lad[i].h] = ++tmp;

        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i)
            lad[i].h = mp[lad[i].h], ++cnt[lad[i].h];

        sort(lad, lad+n, cmp);
        memset(ck, 0, sizeof(ck));
        for (int i = 0; i < n; ++i)
        if (!ck[i])
        {
            if (cnt[lad[i].h] <= 1)
                continue;

            vector<int> v;
            v.push_back(lad[i].x);
            for (int j = i+1; j < n && cnt[lad[i].h] && lad[j].h <= lad[i].h; ++j)
            {
                if (lad[j].h == lad[i].h)
                    v.push_back(lad[j].x), ck[j] = true;
            }

            res = (res + f(v)) % MODD;
        }

        printf("Case #%d: %lld\n", tt, res);
    }
    return 0;
}
