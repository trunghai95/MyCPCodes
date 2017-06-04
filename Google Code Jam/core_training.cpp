#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int test, n, k, u, p;
char s[20];
double a[MAXN+2], dp[MAXN+2][MAXN+2];

int read() {
    scanf("%s", s);
    int t1, t2;
    sscanf(s, "%d.%d", &t1, &t2);
    return t1 * 10000 + t2;
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d", &n, &k);
        u = read();
        priority_queue<int, vector<int>, greater<int> > heap;

        for (int i = 1; i <= n; ++i) {
            p = read();
            heap.push(p);
        }

        while (u --> 0) {
            p = heap.top();
            heap.pop();
            heap.push(p + 1);
        }

        for (int i = 1; i <= n; ++i) {
            p = heap.top();
            heap.pop();
            a[i] = 1.0 * p / 10000.0;
        }

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = a[i];
            for (int j = 1; j < i; ++j)
            for (int c = 1; c <= j; ++c) {
                dp[i][c+1] += dp[j][c] * a[i];
            }
        }

        double res = 1;
        for (int i = 1; i <= n; ++i)
            res *= 1.0 - dp[i][k];
        res = 1 - res;

        printf("Case #%d: %.6lf\n", tt, res);
    }
    return 0;
}
