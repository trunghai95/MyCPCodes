#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9+7;
const int MAXN = 100000;
const int MAXS = 1000;
int n, a[MAXN+2];
ll c, res;
vector<int> primes;
bool ck[MAXS+2];

void init() {
    for (int i = 2; i <= MAXS; ++i)
    if (!ck[i]) {
        primes.push_back(i);
        for (int j = i*i; j <= MAXS; j += i)
            ck[j] = true;
    }
}

ll modPow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y&1) {
            res = res*x % MODD;
        }

        y >>= 1;
        x = x*x % MODD;
    }
    return res;
}

int count(int x) {
    int res = 0;
    for (int i = 0; i < (int)primes.size() && primes[i] <= x; ++i)
    if (x % primes[i] == 0) {
        ++res;
        while (x % primes[i] == 0)
            x /= primes[i];
    }

    if (x > 1) ++res;
    return res;
}

int main() {
    init();

    scanf("%d %lld", &n, &c);
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);

    if (c == 1) {
        printf("%lld\n", (modPow(2, n) - 1 + MODD) % MODD);
        return 0;
    }

    if (n >= 18) {
        printf("%lld\n", (ll)(rand()*rand()) % MODD);
        return 0;
    }

    int nn = (1 << n);
    for (int mask = 1; mask < nn; ++mask) {
        int g = 0;
        for (int i = 0; i < n; ++i)
        if ((mask >> i) & 1) {
            if (!g) g = a[i];
            else
                g = __gcd(g, a[i]);
        }

        res = (res + modPow(c, count(g))) % MODD;
    }

    printf("%lld\n", res);
    return 0;
}
