#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int test, n, a[MAXN+2], m, sum[MAXN+2], lef[MAXN+2], rig[MAXN+2];

int main() {
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            sum[i] = sum[i-1] + a[i];
        }

        stack<int> s;
        for (int i = 1; i <= n; ++i) {
            while (!s.empty() && a[s.top()] > a[i]) {
                s.pop();
            }
            if (s.empty()) {
                lef[i] = i;
            } else {
                lef[i] = s.top();
            }

            s.push(i);
        }

        while (!s.empty()) s.pop();
        for (int i = n; i >= 1; --i) {
            while (!s.empty() && a[s.top()] > a[i]) {
                s.pop();
            }
            if (s.empty()) {
                rig[i] = i;
            } else {
                rig[i] = s.top();
            }

            s.push(i);
        }

        int res = 0;
        for (int i = 1; i <= n; ++i)
        if (a[i] == m) {
            int l = lef[i] + 1;
            int r = rig[i] - 1;
            if (lef[i] == i) l = 1;
            if (rig[i] == i) r = n;
            res = max(res, sum[r] - sum[l-1]);
        }

        printf("%d\n", res);
    }
    return 0;
}
