#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int res[100001];
bool ck[100001];
vector<ll> pr;

void init()
{
    for (ll i = 2; i <= 100000; ++i)
    if (!ck[i])
    {
        pr.push_back(i);
        for (ll j = i*i; j <= 100000; j += i)
            ck[j] = true;
    }

    for (ll i = 2; i <= 100000; ++i)
    {
        bool f = false;
        for (int j = 0; j < pr.size() && pr[j]*pr[j] <= i; ++j)
        {
            if (i % pr[j] == 0)
            {
                ++res[pr[j]];
                f = true;
                break;
            }
        }

        if (!f) ++res[i];
    }
}

int n;
ll x;

int main()
{
    init();
    scanf("%d", &n);

    while (n--)
    {
        scanf("%lld", &x);
        if (x > 100000)
            printf("0\n");
        else printf("%d\n", res[x]);
    }
    return 0;
}
