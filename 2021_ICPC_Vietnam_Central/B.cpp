#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 1005;
const ll MOD = 1'000'000'007;

int n, cnt0, cntNeg, maxNegi;
ll a[MAXN], res;

int main() {
    scanf("%d", &n);
    cnt0 = 0;
    cntNeg = 0;
    maxNegi = -1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", a+i);
        if (a[i] == 0) {
            cnt0++;
        } else if (a[i] < 0) {
            cntNeg++;
            if (maxNegi == -1 || a[i] > a[maxNegi]) {
                maxNegi = i;
            }
        }
    }

    res = 1;
    if (cnt0 > 1) {
        res = 0;
    } else if (cnt0 == 1 && cntNeg & 1) {
        res = 0;
    } else if (cnt0 == 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                res = res * a[i] % MOD;
            }
        }
    } else if (cntNeg & 1) {
        for (int i = 0; i < n; i++) {
            if (i != maxNegi) {
                res = res * a[i] % MOD;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            res = res * a[i] % MOD;
        }
    }

    printf("%lld\n", res);
    return 0;
}