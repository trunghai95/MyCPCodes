#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, t[MAXN+5], cnt[MAXN+5];

void inc(int u, int v) {
    if (u > v) {
        inc(u, n-1);
        inc(0, v);
        return;
    }

    ++cnt[u];
    --cnt[v+1];
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", t+i);
        if (t[i] >= n) continue;
        inc((i+1)%n, (i-t[i]+n)%n);
    }

    for (int i = 1; i < n; ++i)
        cnt[i] += cnt[i-1];

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] > cnt[res]) {
            res = i;
        }
    }

    printf("%d\n", res+1);
    return 0;
}
