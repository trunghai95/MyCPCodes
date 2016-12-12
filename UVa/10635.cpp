#include <bits/stdc++.h>

using namespace std;

const int MAXN = 250*250;
int test, n, m, q, a, p[MAXN+5];
vector<int> v;

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d %d", &q, &n, &m);
        memset(p, -1, sizeof(p));
        v.clear();
        vector<int> lis;

        for (int i = 0; i <= n; ++i)
            scanf("%d", &a), p[a] = i;
        for (int j = 0; j <= m; ++j) {
            scanf("%d", &a);
            if (p[a] != -1)
                v.push_back(p[a]);
        }

        for (int i = 0; i < (int)v.size(); ++i) {
            int pos = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            if (pos == (int)lis.size()) {
                lis.push_back(v[i]);
            } else {
                lis[pos] = v[i];
            }
        }


        printf("Case %d: %d\n", tt, (int)lis.size());
    }
    return 0;
}
