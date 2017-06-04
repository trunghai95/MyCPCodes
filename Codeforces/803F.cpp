#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
const ll MODD = 1e9 + 7;
int n, a;
ll cnt[MAXN+2], pow2[MAXN+2];

void init() {
    pow2[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        pow2[i] = pow2[i-1] * 2 % MODD;
    }
}

int main() {
    init();

    scanf("%d", &n);
    while (n --> 0) {
        scanf("%d", &a);
        int j = 1;
        while (j*j < a) {
            if (a % j == 0) {
                ++cnt[j];
                ++cnt[a/j];
            }
            ++j;
        }
        if (j*j == a) {
            ++cnt[j];
        }
    }

    for (int i = MAXN; i >= 1; --i) {
        cnt[i] = pow2[cnt[i]] - 1;
        for (int j = i*2; j <= MAXN; j += i) {
            cnt[i] = (cnt[i] - cnt[j] + MODD) % MODD;
        }
    }

    printf("%lld\n", cnt[1]);
    return 0;
}
