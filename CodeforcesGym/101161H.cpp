#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int test, k, m, n;
pii a[10];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d %d", &k, &m, &n);

        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i].F);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i].S);

        sort(a, a+n);
        int res = 0;

        do {
            // for (int i = 0; i < n; ++i)
            //     cout << a[i].F << '-' << a[i].S << ' ';
            // cout << '\n';
            int ene = 100, tox = 0;
            int cnt = 0, i = 0;

            while (true) {
                // cout << i << ' ' << ene << ' ' << tox << '\n';
                if (ene <= k) {
                    while (i < n && (a[i].F + ene <= k || a[i].S + tox >= 100)) ++i;
                    if (i >= n)
                        break;
                    ene = min(100, ene + a[i].F);
                    tox += a[i].S;
                    ++i;
                } else {
                    if (i < n && a[i].F + ene <= 100 && a[i].S + tox < 100) {
                        ene += a[i].F;
                        tox += a[i].S;
                        ++i;
                    }
                }
                
                // cout << i << ' ' << ene << ' ' << tox << '\n';
                ene -= k;
                tox = max(0, tox - m);
                ++cnt;
            }
            // cout << cnt << '\n';

            res = max(res, cnt);
        } while (next_permutation(a, a+n));

        printf("%d\n", res);
    }
    return 0;
}
