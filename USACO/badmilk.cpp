#include <bits/stdc++.h>

using namespace std;

struct Event
{
    int type; // 0: drink, 1: sick
    int person, milk, time;
};

bool cmp(const Event& x, const Event& y)
{
    if (x.time == y.time)
        return x.type > y.type;
    return x.time < y.time;
}

bool drMilk[60][60];
Event ev[2000];
int n, m, d, s, cnt[60];
bool notbad[60];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    cin >> n >> m >> d >> s;
    for (int i = 0; i < d; ++i)
    {
        cin >> ev[i].person >> ev[i].milk >> ev[i].time;
        ev[i].type = 0;
    }
    for (int i = 0; i < s; ++i)
    {
        cin >> ev[d+i].person >> ev[d+i].time;
        ev[d+i].type = 1;
    }

    sort(ev, ev+d+s, cmp);

    for (int i = 0; i < d+s; ++i)
    {
        if (ev[i].type == 0)
        {
            if (!drMilk[ev[i].person][ev[i].milk])
                drMilk[ev[i].person][ev[i].milk] = true, ++cnt[ev[i].milk];
        }
        else
        {
            for (int j = 1; j <= m; ++j)
            if (!drMilk[ev[i].person][j]) notbad[j] = true;
        }
    }

    int res = 0;
    for (int i = 1; i <= m; ++i)
    if (!notbad[i])
        res = max(res, cnt[i]);
    cout << res;
    return 0;
}
