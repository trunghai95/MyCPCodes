#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5+5;
int n, q, z[MAXN], cnt[MAXN], l, r;
bool isSuf[MAXN];
char s[MAXN];

void proc() {
    n = strlen(s);
    cnt[n] = 1;
    isSuf[n] = true;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i-l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i+z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }

        cnt[z[i]]++;
        if (z[i] == n - i) {
            isSuf[z[i]] = true;
        }
    }
    for (int i = n-1; i >= 1; i--) {
        cnt[i] += cnt[i+1];
    }

    // for (int i = 1; i <= n; i++) {
    //     printf("%d %d %d\n", i, isSuf[i], cnt[i]);
    // }
}

int main() {
    scanf("%s %d", s, &q);
    proc();
    while (q --> 0) {
        scanf("%d", &l);
        if (!isSuf[l] || cnt[l] < 3) {
            printf("NO\n");
        } else {
            printf("YES %d\n", cnt[l]);
        }
    }
    return 0;
}