#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int test, n, k, a;
bool ck[MAXN+2];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        memset(ck, 0, sizeof(ck));
        scanf("%d %d", &n, &k);

        while (n --> 0) {
            scanf("%d", &a);
            ck[a] = true;
        }

        int cur = 0;

        while (k --> 0) {
            while (ck[cur]) ++cur;
            ck[cur] = true;
        }

        while (ck[cur]) ++cur;
        printf("%d\n", cur);
    }
    return 0;
}
