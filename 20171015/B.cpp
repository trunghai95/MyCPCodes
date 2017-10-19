#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5;
int test, n, q;
ll a[MAXN+2], h[MAXN+2], x, wf[MAXN+2], sumh[MAXN+2];

int main() {
    scanf("%d", &test);

    h[0] = 1e18;
    a[0] = -1;

    while (test --> 0) {
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
            scanf("%lld", a+i);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", h+i);
        }

        stack<int> s;
        s.push(0);
        for (int i = 1; i <= n; ++i) {
            sumh[i] = sumh[i-1] + h[i];

            while (h[s.top()] <= h[i]) {
                s.pop();
            }

            int lef = s.top();
            s.push(i);

            wf[i] = wf[lef] + h[i] * (a[i] - a[lef] - 1) - (sumh[i-1] - sumh[lef]);
        }

        scanf("%d", &q);

        while (q --> 0) {
            scanf("%lld", &x);
            int lo = 0, hi = n;

            while (lo < hi) {
                int mid = (lo + hi) / 2 + 1;

                if (x > wf[mid]) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }

            printf("%d\n", lo);
        }
    }
    return 0;
}
