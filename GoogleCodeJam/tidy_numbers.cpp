#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 20;
int test, n, last;
char s[MAXN+2];
ll res;

bool Try(int p) {
    if (p > n) {
        last = max(last, p-1);
        return true;
    }
    if (s[p] < s[p-1]) {
        return false;
    }
    if (Try(p+1)) {
        last = max(last, p-1);
        return true;
    }
    if (p > 1 && s[p] > s[p-1]) {
        last = max(last, p-1);
        return true;
    }
    return false;
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%s", s+1);
        n = strlen(s+1);
        last = 0;
        Try(1);

        if (last < n) {
            --s[last + 1];
        }
        for (int i = last + 2; i <= n; ++i) {
            s[i] = '9';
        }

        sscanf(s+1, "%lld", &res);

        printf("Case #%d: %lld\n", tt, res);
    }
    return 0;
}
