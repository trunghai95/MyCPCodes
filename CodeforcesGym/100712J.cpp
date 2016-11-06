#include <bits/stdc++.h>

using namespace std;

int test, n, m, a, cnta[20], cntb[60];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d", &n, &m);

        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));

        while (n --> 0) {
            scanf("%d", &a);
            ++cnta[a];
        }
        while (m --> 0) {
            scanf("%d", &a);
            ++cntb[a];
        }

        bool ok = true;
        int i = 5, j = 1;
        while (cnta[i] == 0) ++i;

        while (i <= 15) {
            while (j <= 50 && cntb[j] < cnta[i]) ++j;

            if (j > 50) { ok = false; break; }

            ++i, ++j;
            while (i <= 15 && cnta[i] == 0) ++i;
        }

        printf("%s\n", ok?"YES":"NO");
    }
    return 0;
}