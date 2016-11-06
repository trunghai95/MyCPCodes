#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int m, c, n, pos[111], x;
vector<int> r[111];
list<int> desk[20];

int main() {
    while (true) {
        scanf("%d %d %d", &m, &c, &n);
        if (!m && !c && !n) return 0;

        for (int i = 1; i <= n; ++i) {
            r[i].clear();
            int cnt;
            scanf("%d", &cnt);
            while (cnt --> 0) {
                scanf("%d", &x);
                r[i].push_back(x);
            }
        }

        for (int i = 1; i <= m+1; ++i)
            desk[i].clear();

        for (int i = 1; i <= 100; ++i) {
            pos[i] = m+1;
            desk[m+1].push_back(i);
        }

        ll res = 0;
        for (int j = 0; j < 50; ++j)
        for (int i = 1; i <= n; ++i)
        if (j < (int)r[i].size()) {
            int u = r[i][j];

            res += pos[u];
            list<int>::iterator it = desk[pos[u]].begin();
            while (*it != u) ++it;

            desk[pos[u]].erase(it);

            if ((int)desk[1].size() < c) {
                pos[u] = 1;
                desk[1].push_back(u);
                ++res;
                continue;
            }

            for (int i = 2; i <= m+1; ++i) {
                if (i == m+1 || (int)desk[i].size() < c) {
                    desk[i].push_front(u);
                    pos[u] = i;
                    res += i;
                    break;
                }
            }

            int v = desk[1].front();
            desk[1].pop_front();
            ++res;
            for (int i = 2; i <= m+1; ++i) {
                if (i == m+1 || (int)desk[i].size() < c) {
                    desk[i].push_back(v);
                    pos[v] = i;
                    res += i;
                    break;
                }
            }

            desk[pos[u]].pop_front();
            res += pos[u];

            pos[u] = 1;
            desk[1].push_back(u);
            ++res;
        }

        printf("%lld\n", res);
    }
    return 0;
}