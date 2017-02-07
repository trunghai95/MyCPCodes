#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int test, n, a;
long long cnta[MAXN+2], cntb[MAXN+2];
bool ck[MAXN+2];

void solve() {
    for (int i = 1; i <= n; ++i) {
        int found = 0;
        for (int j = 1; j <= n; ++j)
        if (!ck[j] && cnta[i] == cntb[j]) {
            found = j;
            break;
        }
        if (found) {
            ck[found] = true;
        } else {
            printf("Impossible\n");
            return;
        }
    }
    printf("Possible\n");
}

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);

        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a);
            cnta[i] += a;
            cntb[j] += a;
        }

        memset(ck, 0, sizeof(ck));

        solve();
    }
    return 0;
}
