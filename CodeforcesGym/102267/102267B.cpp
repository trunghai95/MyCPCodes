#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MAXN = 10000007;
bool notPrime[MAXN];
ll n;

int main() {
    notPrime[1] = true;
    for (ll i = 2; i < MAXN; i++) {
        if (notPrime[i]) {
            continue;
        }
        for (ll j = i*i; j < MAXN; j += i) {
            notPrime[j] = true;
        }
    }

    scanf("%lld", &n);
    for (ll i = 2; i <= n - i; i++) {
        if (!notPrime[i] && !notPrime[n-i]) {
            printf("%lld %lld\n", i, n-i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}