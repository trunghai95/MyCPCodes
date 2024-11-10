#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define ppi pair<pii,int>

void solve() {
    int n, m;
    int sum1 = 0;

    scanf("%d %d", &n, &m);
    vector<vector<int>> a(n);
    vector<int> cnt1(n, 0);
    for (int i = 0; i < n; i++) {
        a[i] = vector<int>(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            // printf("a[%d][%d]=%d\n", i, j, a[i][j]);
            if (a[i][j]) {
                cnt1[i]++;
                sum1++;
            }
        }
    }
    if (sum1 % n != 0) {
        printf("-1\n");
        return;
    }
    int target = sum1 / n;
    vector<queue<int>> q(m);
    for (int i = 0; i < n; i++) {
        if (cnt1[i] > target) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    q[j].push(i);
                }
            }
        }
    }

    vector<ppi> res;

    for (int i = 0; i < n; i++) {
        // printf("%d %d %d\n", i, cnt1[i], target);
        for (int j = 0; j < m && cnt1[i] < target; j++) {
            if (a[i][j]) {
                continue;
            }
            int ii = -1;
            while (!q[j].empty()) {
                ii = q[j].front();
                q[j].pop();
                if (cnt1[ii] > target) {
                    break;
                }
                ii = -1;
            }
            if (ii == -1) {
                continue;
            }
            res.push_back(ppi(pii(i+1, ii+1), j+1));
            cnt1[i]++;
            cnt1[ii]--;
        }
        if (cnt1[i] < target) {
            printf("-1\n");
            return;
        }
    }

    printf("%ld\n", res.size());
    for (int i = 0; i < res.size(); i++) {
        printf("%d %d %d\n", res[i].first.first, res[i].first.second, res[i].second);
    }
}

int main() {
    int test;
    scanf("%d", &test);

    while (test --> 0) {
        solve();
    }
    return 0;
}