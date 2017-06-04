#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3e5;
const ll MODD = 1e9 + 7;
int n;
ll x[MAXN+2], pow2[MAXN+2], res;

void init() {
    pow2[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        pow2[i] = pow2[i-1] * 2 % MODD;
    }
}

int main() {
    init();
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", x+i);
    }

    sort(x+1, x+1+n);

    for (int i = 1; i <= n; ++i) {
        res = (res + x[i] * (pow2[i-1] - 1)) % MODD;
        int j = n - i + 1;
        res = (res - x[i] * (pow2[j-1] - 1) + MODD*MODD) % MODD;
    }

    printf("%lld\n", res);
    return 0;
}
