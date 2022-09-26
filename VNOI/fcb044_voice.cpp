#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int n, a[MAXN], pre[MAXN], suf[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }

    pre[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            pre[i] = 1;
        } else {
            pre[i] = pre[i-1] + 1;
        }
    }

    suf[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        if (a[i] < a[i+1]) {
            suf[i] = 1;
        } else {
            suf[i] = suf[i+1] + 1;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        // printf("%d %d %d\n", i, pre[i], suf[i]);
        res = max(res, pre[i] + suf[i] - 1);
    }
    printf("%d\n", res);
    return 0;
}