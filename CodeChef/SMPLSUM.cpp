#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 1e7;
const int MINTEST = 2;
ll f[MAXN + 1];
bool notPrime[MAXN + 1];
vector<ll> primes;
ll n;
int test;

ll gcd(ll x, ll y)
{
    if (!x || !y) return x + y;

    return (x > y) ? gcd(x%y, y) : gcd(y%x, x);
}

ll trau()
{
    ll res = 0;
    for (ll i = 1; i <= n; ++i)
        res += n / gcd(n, i);

    return res;
}

void init()
{
    memset(f, -1, sizeof(f));
    memset(notPrime, 0, sizeof(notPrime));
    f[1] = 1LL;

    for (ll k = 2; k <= MAXN; ++k)
    {
        if (f[k] != -1)
            continue;

        if (!notPrime[k])
        {
            ll tmp = MAXN / k;
            for (ll j = k; j <= tmp; ++j)
                notPrime[j*k] = true;

            ll x = k, xt = 1;
            while (x <= MAXN)
                f[x] = f[xt] + x*(x - xt), xt = x, x *= k;

            primes.push_back(k);
        }

        else
        {
            int i;
            for (i = 0; i < primes.size(); ++i)
            if (k % primes[i] == 0)
                break;

            ll tmpk = k;
            ll tmp = 1;
            while (tmpk % primes[i] == 0)
            {
                tmpk /= primes[i];
                tmp *= primes[i];
            }

            f[k] = f[tmpk] * f[tmp];
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    freopen("in.txt", "r", stdin);
    scanf("%d", &test);
    if (test >= MINTEST)
    {
        init();
        while (test--)
        {
            scanf("%lld", &n);
            printf("%lld\n", f[n]);
        }
    }

    else while (test--)
    {
        scanf("%lld", &n);
        printf("%lld\n", trau());
    }

    return 0;
}
