#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int n, k, st[MAXN], res;
char s[20];

int count(int a, int b) {
    int res = 0;
    while (a && b) {
        if ((a&1) == (b&1)) {
            res++;
        }
        a >>= 1;
        b >>= 1;
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < k; j++) {
            st[i] <<= 1;
            if (s[j] == 'T') {
                st[i] |= 1;
            }
        }
        // printf("%d\n", st[i]);
    }

    int bound = 1 << k;
    for (int b = 0; b < bound; b++) {
        int m = k;
        for (int i = 0; i < n; i++) {
            m = min(m, count(st[i], b));
        }
        res = max(res, m);
    }
    printf("%d\n", res);
    return 0;
}