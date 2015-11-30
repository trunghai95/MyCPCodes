#include <bits/stdc++.h>

using namespace std;

#define maxn 100007

char s[maxn], tmp;
int m, l, r, i, res, len, t[maxn];

void update(int x)
{
    while (x <= maxn)
    {
        ++t[x];
        x = x + (x&(-x));
    }
}

int get(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += t[x];
        x = x - (x&(-x));
    }
    return res;
}

int main()
{
    memset(t, 0, sizeof(t));
    cin >> s+1;
    len = strlen(s+1);
    for (i = 1; i < len; ++i)
    {
        if (s[i] == s[i+1])
            update(i);
    }

    cin >> m;
    while (m-- > 0)
    {
        cin >> l >> r;
        res = get(r-1) - get(l-1);
        cout << res << endl;
    }
    return 0;
}
