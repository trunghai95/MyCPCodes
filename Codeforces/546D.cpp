#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool ck[5000001];
ll cnt[5000001];
vector<int> pr;

void init()
{
    cnt[0] = cnt[1] = 0;

    for (ll i = 2; i <= 5000000; ++i)
    {
        if (!ck[i])
        {
            cnt[i] = 1;
            pr.push_back(i);
            for (ll j = i*i; j <= 5000000; j += i)
                ck[j] = true;
        }
        else
        {
            for (ll j = 0; j < pr.size(); ++j)
            if (i % pr[j] == 0)
            {
                cnt[i] = cnt[i / pr[j]] + 1;
                break;
            }
        }
    }

    for (int i = 2; i <= 5000000; ++i)
        cnt[i] = cnt[i-1] + cnt[i];
}

int main()
{
    init();
    int test, a, b;
    scanf("%d", &test);

    while (test--)
    {
        scanf("%d %d", &a, &b);
        printf("%lld\n", cnt[a] - cnt[b]);
    }
    return 0;
}
