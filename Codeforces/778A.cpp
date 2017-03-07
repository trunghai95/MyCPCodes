#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n, m, a[MAXN+2];
char s[MAXN+2], t[MAXN+2];
bool ck[MAXN+2];

bool check(int x) {
    memset(ck, 0, sizeof(ck));

    for (int i = 1; i <= x; ++i)
        ck[a[i]] = true;

    int j = 1;
    for (int i = 1; i <= n && j <= m; ++i) {
        if (ck[i]) continue;
        if (s[i] == t[j]) ++j;
    }

    return (j > m);
}

int main() {
    scanf("%s %s", s+1, t+1);
    n = strlen(s+1);
    m = strlen(t+1);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    int lo = 0, hi = n;

    while (lo < hi) {
        int mid = (lo + hi) / 2 + 1;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", lo);
    return 0;
}
