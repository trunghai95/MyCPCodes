#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
char s[MAXN+2];
int n, cnt[30], x;

void solve() {
    for (int i = 1; i <= 26; ++i) {
        if (x % i == 0 && x / i <= cnt[i]) {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
}

int main() {
    scanf("%s", s+1);
    n = strlen(s+1);
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != s[i-1]) {
            cur = 1;
        } else {
            ++cur;
        }

        cnt[s[i] - 'a' + 1] = max(cnt[s[i] - 'a' + 1], cur);
    }

    scanf("%d", &n);

    while (n --> 0) {
        scanf("%d", &x);
        solve();
    }
    return 0;
}
