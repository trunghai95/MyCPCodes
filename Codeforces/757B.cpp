#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int n, a, cnt[MAXN+2];

void proc() {
    int i;
    for (i = 1; i*i < a; ++i) {
        if (a % i == 0) {
            ++cnt[i];
            ++cnt[a/i];
        }
    }
    if (a/i == i) ++cnt[i];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        proc();
    }

    int res = 1;
    for (int i = 2; i <= MAXN; ++i) {
        res = max(res, cnt[i]);
    }

    printf("%d\n", res);
    return 0;
}
