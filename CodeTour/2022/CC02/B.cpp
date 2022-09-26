#define ll long long

#include <stdio.h>

using namespace std;

const int MAXN = 200005;
const ll MOD = 1000000007;
int n, cnt[MAXN];
ll a[MAXN];

ll mod(ll x) {
    x %= MOD;
    if (x < 0) {
        x += MOD;
    }
    return x;
}

void solveSmall() {
    ll res = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        ll sumProd = 0;
        int len = 0;
        for (int j = i; j >= 1; j--) {
            len++;
            sumProd += mod(sum * a[j]);
            sum = mod(sum + a[j]);

            if (i == n) {
                // printf("%d %d cnt:%d sumProd:%lld\n", j, i, cnt[j-1], sumProd);
                res = mod(res + mod(sumProd * cnt[j-1]));
            } else if (i % len == 0) {
                // printf("%d %d %lld\n", j, i, sumProd);
                res = mod(res + sumProd);
                if (len >= n - i) {
                    ++cnt[i];
                }
            }
        }
    }

    printf("%lld\n", res);
}

void solveSame() {
    ll res = 0;
    cnt[0] = 1;
    for (int i = 1; i < n; i++) {
        for (ll len = 1; len*len <= i; len++) {
            ll sumProd = mod(len*(len-1)/2);
            res = mod(res + sumProd);
            if (len >= n-i) {
                ++cnt[i];
            }

            if (len*len != i) {
                ll len2 = i / len;
                sumProd = mod(len2*(len2-1)/2);
                res = mod(res + sumProd);
                if (len2 >= n-i) {
                    ++cnt[i];
                }
            }
        }
    }

    for (ll len = 1; len <= n; len++) {
        ll sumProd = mod(len*(len-1)/2);
        res = mod(res + mod(sumProd * cnt[n - len]));
        // printf("%d %d %d %lld\n", n - len+1, n, cnt[n-len], sumProd);
    }

    printf("%lld\n", mod(res*mod(a[1]*a[1])));
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a+i);
    }
    bool allSame = true;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[1]) {
            allSame = false;
            break;
        }
    }
    if (!allSame) {
        solveSmall();
    } else {
        solveSame();
    }
}