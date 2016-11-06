// TLE

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30003;
const int BLKSZ = 175;
int n, a[MAXN], b[MAXN], q, u, v, k, nblock, cnt[MAXN/BLKSZ + 3][MAXN];
int res, ublock, vblock;
map<int,int> mp;

int main() {
    scanf("%d", &n);
    nblock = (n - 1) / BLKSZ + 1;

    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
        b[i] = a[i];
    }

    sort(b, b+n);
    mp[b[0]] = mp.size();
    for (int i = 1; i < n; ++i)
    if (b[i] != b[i-1]) {
        mp[b[i]] = mp.size();
    }

    for (int i = 0; i < n; ++i) {
        a[i] = mp[a[i]];
        ++cnt[i/BLKSZ][a[i]];
    }

    for (int i = 0; i < nblock; ++i) {
        for (int j = MAXN - 2; j >= 0; --j) {
            cnt[i][j] += cnt[i][j+1];
        }
    }

    scanf("%d", &q);
    while (q --> 0) {
        scanf("%d %d %d", &u, &v, &k);
        --u, --v, ++k;
        map<int,int>::iterator it = mp.lower_bound(k);
        if (it == mp.end()) {
            printf("0\n");
            continue;
        }

        k = it->second;
        res = 0, ublock = u/BLKSZ, vblock = v/BLKSZ;
        
        for (int i = ublock*BLKSZ; i < u; ++i) {
            res -= (a[i] >= k);
        }

        int tmp = min((vblock+1)*BLKSZ, n);
        for (int i = v + 1; i < tmp; ++i) {
            res -= (a[i] >= k);
        }

        for (int i = ublock; i <= vblock; ++i) {
            res += cnt[i][k];
        }
        printf("%d\n", res);
    }
    return 0;
}
