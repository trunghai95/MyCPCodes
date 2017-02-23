#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, a[MAXN+2], mx, mn;

int main() {
    scanf("%d", &n);

    mx = 0, mn = 1e9;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        mx = max(a[i], mx);
        mn = min(a[i], mn);
    }

    int res = 0;

    for (int i = 1; i <= n; ++i) {
        if (a[i] > mn && a[i] < mx) {
            ++res;
        }
    }

    cout << res << '\n';
    return 0;
}
