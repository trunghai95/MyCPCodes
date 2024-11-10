#include <bits/stdc++.h>

using namespace std;

const int MAXM = 100005;
int n, m, k, a[MAXM];

bool solve() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+m, greater<int>());
    int bin = 0;
    int taken = 0;
    for (int i = 0; i < m; i++) {
        int cnt = n/k;
        if (bin < n % k) {
            cnt++;
        }
        if (a[i] > cnt) {
            return false;
        }
        if (a[i] == cnt) {
            bin++;
            continue;
        }
        if (a[i] < cnt - taken) {
            taken += a[i];
        } else if (a[i] == cnt - taken) {
            taken = 0;
            bin++;
        } else {
            bin++;
            taken = cnt - a[i];
        }
    }
    return true;
}

int main() {
    int test;
    scanf("%d", &test);
    while (test --> 0) {
        if (solve()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}