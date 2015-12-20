#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cnt[300], q, n, lastcnt;
char last, x;
char order[15];
bool dir;

ll f(char c, ll ccnt)
{
    ccnt -= lastcnt;
    char tmp;
    if (!dir)
        tmp = (last - 'a' + (ccnt % 26)) % 26 + 'a';
    else
        tmp = (last - 'a' - (ccnt % 26) + 26) % 26 + 'a';

    int res = ccnt / 26;
    if (!dir)
    {
        if ((last < tmp && c > last && c <= tmp)
            || (last > tmp && (c > last || c <= tmp)))
            ++res;
    }
    else
    {
        if ((last > tmp && c < last && c >= tmp)
            || (last < tmp && (c < last || c >= tmp)))
            ++res;
    }

    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &q);
    last = 'z';
    lastcnt = 0;

    for (int i = 0; i < q; ++i)
    {
        scanf("%s", order);
        if (!strcmp(order, "SMJER"))
        {
            scanf("%lld", &n);
            for (char c = 'a'; c <= 'z'; ++c)
                cnt[c] += f(c, n);
            if (!dir)
                last = (last - 'a' + ((n - lastcnt) % 26)) % 26 + 'a';
            else
                last = (last - 'a' - ((n - lastcnt) % 26) + 26) % 26 + 'a';
            lastcnt = n;
            dir = !dir;
        }
        else
        {
            scanf("%lld %c", &n, &x);
            printf("%lld\n", f(x,n) + cnt[x]);
        }
    }
    return 0;
}
