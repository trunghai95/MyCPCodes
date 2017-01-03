#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000000;
const int MAXA = 10000000;
int n, a[MAXN+1];
ll k;
ll cnt[MAXA+1];

ll count(int m) {
    memset(cnt, 0, m*sizeof(ll));
    
    for (int i = m; i <= MAXA; ++i) {
        int j = i/2;
        int k = i - j;
        cnt[i] = max(1LL, cnt[j] + cnt[k]);
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res += cnt[a[i]];
    }

    return res;
}

int main() {
    scanf("%d %lld", &n, &k);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);

    int lo = 0, hi = MAXA;

    while (lo < hi) {
        int mid = (lo + hi) / 2 + 1;
        ll tmp = count(mid);
        if (tmp < k) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }

    if (!lo) {
        printf("-1\n");
    } else {
        printf("%d\n", lo);
    }
    return 0;
}
