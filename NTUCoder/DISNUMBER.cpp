#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gt[11], pw[11];

void init()
{
    gt[0] = pw[0] = 1;
    for (int i = 1; i <= 10; ++i)
        gt[i] = gt[i-1] * i, pw[i] = pw[i-1] * 10;
}

ll l, r;
int n;

ll f(ll x)
{
    if (x >= 10000000000LL)
        return f(9999999999LL);
    if (x < 10) return x;

    char s[20];
    lltoa(x, s, 10);
    int len = strlen(s);
    bool ck[10];
    memset(ck, 0, sizeof(ck));
    ll res = f(pw[len - 1] - 1);
    bool f = true;

    {
        int i = 0;
        int digit = s[i] - '0';
        int cnt = 0;
        for (int i = 1; i < digit; ++i)
            cnt += !ck[i];

        res += gt[9-i] / gt[10 - len] * cnt;

        ck[digit] = true;
    }

    for (int i = 1; i < len - 1; ++i)
    {
        int digit = s[i] - '0';
        int cnt = 0;
        for (int i = 0; i < digit; ++i)
            cnt += !ck[i];

        if (f)
        {
            res += gt[9-i] / gt[10 - len] * cnt;
        }

        cnt += !ck[digit];
        if (ck[digit] || !cnt)
            f = false;

        ck[digit] = true;
    }

    int digit = s[len - 1] - '0';
    if (f) for (int i = 0; i < digit; ++i)
        res += !ck[i];

    if (f && !ck[digit]) ++res;

    return res;
}

int main()
{
    init();
    scanf("%d", &n);

    while (n--)
    {
        scanf("%lld %lld", &l, &r);

        ll res = f(r) - f(l - 1);
        printf("%lld\n", res);
    }
    return 0;
}
