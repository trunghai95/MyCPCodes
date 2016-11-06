#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, tt, n, d;
ll res;

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d", &n, &d);
        res = 0;
        for (int i = d; i <= n; i += d) {
            for (int j = i; j <= n; j += i) {
                int c = n - j;
                int b = i + 1;
                int tmp = c/(b+1) + (c % (b+1) != 0);
                res += (ll)max(c/b - tmp + 1, 0);
            }
        }

        printf("Case #%d: %lld\n", ++tt, res);
    }
    return 0;
}
