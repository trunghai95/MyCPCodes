#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n, s, a[MAXN+5], res;
int cnt[MAXN+5];

int main() {
    scanf("%d %d", &n, &s);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);

        if (a[i] == 0 && i != s) {
            a[i] = n+1;
        }
        ++cnt[a[i]];
    }

    if (a[s] != 0) {
        --cnt[a[s]];
        a[s] = 0;
        res = 1;
    }

    sort(a+1, a+1+n);

    int i = n, level = 1;

    while (level < n && level < a[i]) {
        if (!cnt[level]) {
            ++res;
            --i;
        }
        ++level;
    }

    printf("%d\n", res);
    return 0;
}
