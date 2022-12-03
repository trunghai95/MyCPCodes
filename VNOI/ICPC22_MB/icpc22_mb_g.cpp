#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
int test;
char s[MAXN];
ll sum, res, n;

ll val(char c) {
    return c - 'a' + 1;
}

ll solve() {
    scanf("%s", s);
    n = strlen(s);
    res = 0;
    for (int i = 0; i < n; i++) {
        ll l = i;
        ll r = n - i - 1;
        sum = ((l+1)*(r+1)*(l+r+2)/2) % MOD;
        // printf("%lld-", sum);
        res = (res + sum * val(s[i])) % MOD;
    }
    return res;
}

int main() {
    scanf("%d", &test);
    while (test --> 0) {
        printf("%lld\n", solve());
    }
    return 0;
}