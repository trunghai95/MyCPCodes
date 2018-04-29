#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int test, k, n;
char s[MAXN+2];

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%s %d", s, &k);
        n = strlen(s);
        int res = 0;
        for (int i = 0; i <= n - k; ++i)
        if (s[i] == '-') {
            ++res;
            for (int j = 0; j < k; ++j) {
                int u = i+j;
                if (s[u] == '-') {
                    s[u] = '+';
                } else {
                    s[u] = '-';
                }
            }
        }

        bool ok = true;
        for (int i = n - k + 1; i < n; ++i) {
            if (s[i] == '-') {
                ok = false;
                break;
            }
        }

        if (ok) {
            printf("Case #%d: %d\n", tt, res);
        } else {
            printf("Case #%d: IMPOSSIBLE\n", tt);
        }
    }
    return 0;
}
