#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

const ll MAXN = 1e14;
const ll MAXSQRT = 1e7;
int test;
ll n;
bool ck[10000001];
vector<ll> primes;

void init() {
    for (ll i = 2; i <= 10000000; ++i)
    if (!ck[i]) {
        primes.push_back(i);
        for (ll j = i*i; j <= 10000000; j += i)
            ck[j] = true;
    }
}

void solve(ll n) {
    vector<ll> res;
    vector<pli> v;
    for (int i = 0; i < (int)primes.size() && primes[i]*primes[i] <= n; ++i)
    if (n % primes[i] == 0) {
        int cnt = 0;
        while (n % primes[i] == 0) {
            ++cnt;
            n /= primes[i];
        }
        v.push_back(pli(primes[i], cnt));
    }
    if (n > 1) v.push_back(pli(n, 1));
    res.push_back(1);
    for (int i = 0; i < (int)v.size(); ++i) {
        ll tmp = 1;
        int cursize = res.size();
        for (int j = 0; j < v[i].second; ++j) {
            tmp = tmp * v[i].first;
            for (int k = 0; k < cursize; ++k)
                res.push_back(tmp * res[k]);
        }
    }

    sort(res.begin(), res.end());
    res.pop_back();
    for (int i = 1; i < (int)res.size(); ++i)
        printf("%lld ", res[i]);
    printf("\n");
}

int main()
{
    init();

    scanf("%d", &test);

    while (test --> 0) {
        scanf("%lld", &n);
        solve(n);
    }
    return 0;
}
