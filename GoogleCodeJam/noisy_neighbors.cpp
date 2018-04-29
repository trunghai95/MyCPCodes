#include <bits/stdc++.h>

using namespace std;

int test, n, m, k;

int neighCnt(int i, int j) {
    bool edge1 = (i == 0 || i == n-1);
    bool edge2 = (j == 0 || j == m-1);
    if (n == 1) {
        if (edge2) return 1;
        return 2;
    }
    if (edge1 && edge2) {
        return 2;
    }
    if (edge1 || edge2) {
        return 3;
    }
    return 4;
}

int Try(bool f) {
    int cnt = 0, sum = 0;
    vector<int> v;

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        if (((i^j) & 1) != f) {
            ++cnt;
        } else {
            int tmp = neighCnt(i, j);
            v.push_back(tmp);
            sum += tmp;
        }
    }

    if (k <= cnt) {
        return 0;
    } else {
        cnt = k - cnt;
        sort(v.begin(), v.end());
        sum = 0;
        for (int i = 0; i < cnt; ++i)
            sum += v[i];
        return sum;
    }
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        scanf("%d %d %d", &n, &m, &k);
        if (n > m) swap(n, m);
        int res = min(Try(true), Try(false));

        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
