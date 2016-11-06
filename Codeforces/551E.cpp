#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define F first
#define S second
#define debug(x) cout << #x << ": " << (x) << '\n'

const int BLKSZ = 710;
const int MAXN = 500005;

int n, q, nblock, l, r, type;
ll lazy[MAXN/BLKSZ + 1], x;
pli a[MAXN], b[MAXN];

int main() {
    scanf("%d %d", &n, &q);
    nblock = n / BLKSZ + (n % BLKSZ != 0);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &b[i].F);
        b[i].S = i;
    }
    memcpy(a, b, sizeof(b));

    for (int i = 0; i < nblock - 1; ++i) {
        sort(a + i*BLKSZ, a + (i+1)*BLKSZ);
    }
    sort(a + (nblock-1) * BLKSZ, a + n);

    while (q --> 0) {
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d %d %lld", &l, &r, &x);
            --l, --r;
            int lblock = l/BLKSZ, rblock = r/BLKSZ;
            if (lblock == rblock) {
                for (int i = l; i <= r; ++i) {
                    b[i].F += x;
                }
                if (lblock != nblock - 1) {
                    memcpy(a + lblock*BLKSZ, b + lblock*BLKSZ, BLKSZ*sizeof(pli));
                    sort(a + lblock*BLKSZ, a + (lblock+1)*BLKSZ);
                } else {
                    memcpy(a + lblock*BLKSZ, b + lblock*BLKSZ, (n - lblock*BLKSZ)*sizeof(pli));
                    sort(a + lblock*BLKSZ, a + n);
                }
            } else {
                for (int i = lblock + 1; i < rblock; ++i) {
                    lazy[i] += x;
                }

                if (l % BLKSZ == 0) {
                    lazy[lblock] += x;
                } else {
                    for (int i = l; i % BLKSZ != 0; ++i) {
                        b[i].F += x;
                    }
                    memcpy(a + lblock*BLKSZ, b + lblock*BLKSZ, BLKSZ*sizeof(pli));
                    sort(a + lblock*BLKSZ, a + (lblock+1)*BLKSZ);
                }

                if ((r + 1) % BLKSZ == 0) {
                    lazy[rblock] += x;
                } else {
                    for (int i = rblock*BLKSZ; i <= r; ++i) {
                        b[i].F += x;
                    }
                    if (rblock != nblock - 1) {
                        memcpy(a + rblock*BLKSZ, b + rblock*BLKSZ, BLKSZ*sizeof(pli));
                        sort(a + rblock*BLKSZ, a + (rblock+1)*BLKSZ);
                    } else {
                        memcpy(a + rblock*BLKSZ, b + rblock*BLKSZ, (n - rblock*BLKSZ)*sizeof(pli));
                        sort(a + rblock*BLKSZ, a + n);
                    }
                }
            }

        } else {
            scanf("%lld", &x);
            l = r = -1;

            for (int i = 0; i < nblock - 1; ++i) {
                int p = lower_bound(a + i*BLKSZ, 
                    a + (i+1)*BLKSZ, pli(x - lazy[i], 0)) - a;
                if (p < (i+1)*BLKSZ && a[p].F == x - lazy[i]) {
                    l = a[p].S;
                    break;
                }
            }

            if (l == -1) {
                int p = lower_bound(a + (nblock-1)*BLKSZ, 
                    a + n, pli(x - lazy[nblock - 1], 0)) - a;
                if (p < n && a[p].F == x - lazy[nblock - 1]) {
                    l = a[p].S;
                } else {
                    printf("-1\n");
                    continue;
                }
            }

            int p = lower_bound(a + (nblock-1)*BLKSZ, 
                    a + n, pli(x - lazy[nblock - 1] + 1, 0)) - 1 - a;
            if (p >= (nblock-1)*BLKSZ && a[p].F == x - lazy[nblock - 1]) {
                r = a[p].S;
            } else {
                for (int i = nblock - 2; i >= 0; --i) {
                    p = lower_bound(a + i*BLKSZ, 
                        a + (i+1)*BLKSZ, pli(x - lazy[i] + 1, 0)) - 1 - a;
                    if (p >= i*BLKSZ && a[p].F == x - lazy[i]) {
                        r = a[p].S;
                        break;
                    }
                }
            }

            printf("%d\n", r - l);
        }
    }
    return 0;
}