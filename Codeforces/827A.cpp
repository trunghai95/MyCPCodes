#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const int MAXX = 1e6;
const int MAXLEN = 2e6;
int n, p[MAXX+3];
char s[MAXLEN+3];
string t[MAXN+2];

int main() {
    scanf("%d", &n);

    for (int i = 1, k; i <= n; ++i) {
        scanf("%s %d", s, &k);
        t[i] = string(s);

        for (int j = 1, x; j <= k; ++j) {
            scanf("%d", &x);
            --x;

            if (p[x] == 0 || t[p[x]].length() < t[i].length()) {
                p[x] = i;
            }
        }
    }

    int len = 0;

    memset(s, 0, sizeof(s));
    for (int i = 0; i < MAXX; ++i) {
        if (p[i] == 0) continue;
        for (int j = max(len, i); j < (int)t[p[i]].length() + i; ++j) {
            s[j] = t[p[i]][j-i];
        }

        len = max(len, (int)t[p[i]].length() + i);
        fflush(stdout);
    }

    for (int i = 0; i < len; ++i) {
        if (s[i] == 0) s[i] = 'a';
    }
    printf("%s\n", s);

    return 0;
}
