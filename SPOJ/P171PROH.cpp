#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n, a, b;
map<int,int> cnta, cntb;
set<int> vals;

int main() {
    while (scanf("%d", &n) != EOF) {
        cnta.clear();
        cntb.clear();
        vals.clear();

        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &a, &b);
            ++cnta[a];
            vals.insert(a);
            if (a != b) {
                ++cntb[b];
                vals.insert(b);
            }
        }

        n = (n+1)/2;

        int res = INF;
        for (set<int>::iterator it = vals.begin(); it != vals.end(); ++it) {
            int x = *it;
            int tmp = n - cnta[x];
            if (tmp <= 0) {
                res = 0;
                break;
            }

            if (tmp <= cntb[x]) {
                res = min(res, tmp);
            }
        }

        if (res == INF) res = -1;
        printf("%d\n", res);
    }
    return 0;
}
